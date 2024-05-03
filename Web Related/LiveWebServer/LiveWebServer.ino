#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "NETGEAR17";
const char* password = "Rosselin06";

WebServer server(80);

String message = "No message yet.";

void handleRoot() {
  server.send(200, "text/html", "<h1>ESP32 Web Server</h1><p id='message'>Your message: " + message + "</p><input type='text' id='msg'><button onclick='sendMessage()'>Send</button><script>function sendMessage(){var msg=document.getElementById('msg').value;document.getElementById('message').innerHTML='Waiting for response...';var xhr=new XMLHttpRequest();xhr.open('POST','/message',true);xhr.setRequestHeader('Content-Type','application/x-www-form-urlencoded');xhr.send('msg='+msg);xhr.onload=function(){if(xhr.status==200){document.getElementById('message').innerHTML='Your message: '+msg;}else{document.getElementById('message').innerHTML='Failed to send message';}}}</script>");
}

void handleMessage() {
  if (server.hasArg("msg")) {
    message = server.arg("msg");
  }
  server.send(200, "text/plain", "Message received");
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
  server.on("/message", HTTP_POST, handleMessage);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
