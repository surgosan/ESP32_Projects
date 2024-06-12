#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "NETGEAR17";
const char* password = "Rosselin06";

WebServer server(80);

bool fountainStatus = false;
String fountainStatusString = "Fountain OFF";

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
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  server.on("/", handleRoot);
  server.on("/toggle", HTTP_POST, toggleFountain);
  server.begin();
  Serial.println("HTTP server started");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  server.handleClient();

  
}
