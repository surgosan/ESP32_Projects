#include <WiFi.h>
#include <SPI.h>
#include <SD.h>

const char* ssid = "NETGEAR17";
const char* password = "Rosselin06";

const int chipSelect = 5; // Choose any GPIO pin for chip select

WiFiServer server(80); // Initialize the web server on port 80

void setup() {
  Serial.begin(115200);
  delay(10);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize SD card
  if (!SD.begin(chipSelect)) {
    Serial.println("SD card initialization failed!");
    return;
  }
  Serial.println("SD card initialized");

  // Start the web server
  server.begin();
  Serial.println("Web server started");

  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (client) {
    Serial.println("New client connected");
    // Wait for the client to send a request
    while (!client.available()) {
      delay(1);
    }
    // Read the first line of the request
    String request = client.readStringUntil('\r');
    Serial.println(request);
    client.flush();

    // Check if the client's request is for the root URL
    if (request.indexOf("/hello.html") != -1) {
      serveHtmlFile(client, "/hello.html");
    } else {
      // Handle other requests here (e.g., serve other files)
      client.println("HTTP/1.1 404 Not Found");
      client.println("Content-Type: text/html");
      client.println();
      client.println("<h1>404 Not Found</h1>");
    }

    // Close the connection
    client.stop();
    Serial.println("Client disconnected");
  }
}

void serveHtmlFile(WiFiClient client, String fileName) {
  // Open the HTML file
  File file = SD.open(fileName);
  if (file) {
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println();

    // Read and send the file contents
    while (file.available()) {
      client.write(file.read());
    }
    file.close();
  } else {
    // If the file doesn't exist, send a 404 response
    client.println("HTTP/1.1 404 Not Found");
    client.println("Content-Type: text/html");
    client.println();
    client.println("<h1>404 Not Found</h1>");
  }
}
