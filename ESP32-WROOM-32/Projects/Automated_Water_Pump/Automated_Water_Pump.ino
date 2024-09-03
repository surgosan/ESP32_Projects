#include <WiFi.h>
#include <WebServer.h>
#include <time.h>

#define transistorPIN 2
const char* ssid = "NETGEAR17";
const char* password = "Rosselin06";

WebServer server(80);

bool fountainStatus = false;
String fountainStatusString = "Fountain OFF";

// Time variables
const long gmtOffset_sec = -5 * 3600;    // EST offset in seconds
const int daylightOffset_sec = 3600;     // 1 hour for daylight saving time
struct tm timeinfo;

void handleRoot() {
  String html = R"(
    <h1>Yammie's Fountain</h1>
    <p id='message'>Fountain Status: )" + fountainStatusString + R"(</p>
    <button onclick='toggleFountain()'>Toggle Fountain</button>
    <script>
      function toggleFountain() {
        var xhr = new XMLHttpRequest();
        xhr.open('POST', '/toggle', true);
        xhr.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');
        xhr.send();
        xhr.onload = function() {
          if (xhr.status == 200) {
            document.getElementById('message').innerHTML = 'Fountain Status: ' + xhr.responseText;
          } else {
            document.getElementById('message').innerHTML = 'Failed to toggle fountain';
          }
        }
      }
    </script>
  )";

  server.send(200, "text/html", html);
}

void toggleFountain() {
  fountainStatus = !fountainStatus;
  fountainStatusString = fountainStatus ? "Fountain ON" : "Fountain OFF";
  server.send(200, "text/plain", fountainStatusString);
}

void setup() {
  pinMode(transistorPIN, OUTPUT);
  digitalWrite(transistorPIN, LOW);

  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize the NTP client
  configTime(gmtOffset_sec, daylightOffset_sec, "pool.ntp.org");
  while (!getLocalTime(&timeinfo)) {
    Serial.println("Failed to obtain time");
    delay(1000);
  }

  server.on("/", handleRoot);
  server.on("/toggle", HTTP_POST, toggleFountain);
  server.begin();
  Serial.println("HTTP server started");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  if (getLocalTime(&timeinfo)) {
    int currentHour = timeinfo.tm_hour;

    if (currentHour > 6 && currentHour < 23) { // If day
      fountainStatus = true;
      fountainStatusString = "OFF - Turned ON Automatically";
      server.send(200, "text/plain", fountainStatusString);\
    }
  }
}

void loop() {
  server.handleClient();

  if (getLocalTime(&timeinfo)) {
    int currentHour = timeinfo.tm_hour;
    int currentMinute = timeinfo.tm_min;
    // Serial.print("Current time: ");
    // Serial.print(currentHour);
    // Serial.print(":");
    // Serial.println(currentMinute);

    if (currentHour == 23 && currentMinute < 1) {
      // Serial.println("TURNING OFF");
      fountainStatus = false;
      fountainStatusString = "OFF - Turned OFF Automatically";
      server.send(200, "text/plain", fountainStatusString);
    } else if (currentHour == 6 && currentMinute < 1) {
      // Serial.println("TURNING ON");
      fountainStatus = true;
      fountainStatusString = "ON - Turned ON Automatically";
      server.send(200, "text/plain", fountainStatusString);
    }
  }

  if (fountainStatus) {
    digitalWrite(transistorPIN, HIGH);
  } else {
    digitalWrite(transistorPIN, LOW);
  }

  delay(1000);  // Add a delay to reduce CPU usage
}
