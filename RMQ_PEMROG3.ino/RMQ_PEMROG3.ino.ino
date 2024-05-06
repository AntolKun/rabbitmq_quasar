#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.
const char* ssid = "Pasca Dosen";
const char* password = "ublkeceefik";
const char* mqtt_server = "103.167.112.188"; 
const char* mqtt_user = "/iot:kelas_edp";
const char* mqtt_pass= "kelas_edp";
const char* routkey = "routing_edp";

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  // Connecting to a WiFi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  // Loop until we're reconnected
  Serial.println("In reconnect...");
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("Herbantolo - 22421057", mqtt_user, mqtt_pass)) {
      Serial.println("connected");
      Serial.println("WiFi connected");
      Serial.println("IP address: ");
      Serial.println(WiFi.localIP());
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
}

void loop() {
  
  if (!client.connected()) {
    reconnect();
  }

  client.loop();

  // char message[10] = "00"; // Initialize with "00" as the starting value

  // for (char tens = '0'; tens <= '2'; tens++) {
  //   for (char ones = '0'; ones <= (tens == '2' ? '0' : '9'); ones++) {
  //     message[0] = tens;
  //     message[1] = ones;
  //     client.publish(routkey, message);
  //     delay(1000);
  //   }
  // }

   const char* message = "Pemrograman 3 asik";
   client.publish(routkey, message);
   client.subscribe(routkey);
   delay(1000);
}