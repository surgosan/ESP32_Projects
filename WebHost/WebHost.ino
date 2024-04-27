#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "NETGEAR17";
const char* password = "Rosselin06";

WebServer server(80);

void handleRoot() {
  server.send(200, "text/html", "<html><body><h1>Hello, World!</h1></body></html>");
}

void setup() {
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);   // Turn the LED on
  delay(100);              // Wait for 100 milliseconds
  digitalWrite(2, LOW);    // Turn the LED off
  delay(1000);
  Serial.begin(115200);
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  digitalWrite(2, HIGH);   // Turn the LED on
  delay(100);              // Wait for 100 milliseconds
  digitalWrite(2, LOW);    // Turn the LED off
  delay(1000);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  digitalWrite(2, HIGH);   // Turn the LED on
  delay(100);              // Wait for 100 milliseconds
  digitalWrite(2, LOW);    // Turn the LED off
  delay(1000);

  // Print ESP32 IP address
  Serial.println(WiFi.localIP());

  // Define server routes
  server.on("/", handleRoot);

  // Start server
  server.begin();
  Serial.println("HTTP server started");
  delay(2000);

  digitalWrite(2, HIGH);
  delay(100);
  digitalWrite(2, LOW);
  delay(100);
  digitalWrite(2, HIGH);   
  delay(100);
  digitalWrite(2, LOW);
  delay(100);
  digitalWrite(2, HIGH); 
}

void loop() {
  // Handle client requests
  server.handleClient();
}
