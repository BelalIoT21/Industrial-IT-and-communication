// inkluderingsfiler
// PubSubClient.h = till för MQTT, det vill säga Mosquitto
#include <PubSubClient.h>
// WiFi.h finns redan som "standard", du behöver inte inkludera denna i libraries.txt
#include <WiFi.h>
#include <time.h>

// SSID = det trådlösa nätverksnamnet, i det här fallet finns det bara två, har du gratiskonto kan du bara använda nedan.
const char *SSID = "Wokwi-GUEST";
// Kräver inget lösenord, men kräver ändå en variabel. Lämnas tom.
const char *pass = "";
// Publik mosquitto server, var försiktig med vad du skickar.
// ALLA kan lyssna på din topic!
const char *mqttServer = "test.mosquitto.org";
// 1883 = standardporten för MQTT, KAN skiljas, till exempel broker.emqx.io har 8083
const int mqttPort = 1883;
// Vilken topic ska vi lyssna/skicka till/från
const char *minTopic = "Belal.Almshmesh/LED_pushButton_Temp";

// Mac på nätverkskortet
char mac[50];
// Klient identifikation för MQTT (bör vara unikt)
char clientId[50];
// Sträng, mac-adress, lite vänligare att läsa
String stMac;

// initierar trådlös anslutning (vi fejkar det med proxy här)
WiFiClient espClient;
// MQTT-client, Pub/Sub vart finns det trådlösa objektet för anslutningen.
// och den återanvänder vi här, tillsammans med MQTT
PubSubClient client(espClient);

// Led pin (IN/UT-gång)
// D13 = digital 13
const int LEDPIN1 = 12;
// Led pin (IN/UT-gång)
// D13 = digital 12
const int LEDPIN2 = 13;
// push button (IN/UT-gång)
// D15 = digital 15
const int pushButton = 15;
// analog in/utgång, nummer 0
// lyssnar på jitter
const int Analog0 = 0;
int num = 0;
char temp[100];
int lastButton = 0;

// en funktion för att ansluta mot "wifi" (som sagt, fake-anslutning i denna simulator)
void anslutWiFi(void)
{
  // WIFI_AP = ACCESSPUNKT (det vill säga "router")
  // WIFI_STA = STANDARD (det vill säga "klient")
  WiFi.mode(WIFI_STA);
  // Begin = tar emot wifi-nätverksnamnet och lösenordet. (om det finns något lösenord, det vill säga.)
  WiFi.begin(SSID, pass);
  // medan statusen INTE är ansluten, så försöker vi tills vi är anslutna
  while (WiFi.status() != WL_CONNECTED)
  {
      // Varje cykel, väntar vi en halv sekund.
    	delay(500);
      // och visar en punkt för varje gång vi försöker på nytt.
      Serial.print(".");
  }
  // Om vi är anslutna så är allt "bra"
}

// (åter)anslut
// Använder denna för att ansluta OCH (&&) ansluta på nytt.
void mqttAteranslut()
{
  // medan clienten för MQTT inte är ansluten, så försöker vi ansluta till "brokern/mäklaren"
  while (!client.connected())
  {
    // meddelande 
    Serial.println("Försöker att återansluta till MQTT-servern");
    // Slumpmässigt nummer
    long rand = random(1000);
    // espId-(random nummer)
    // Sammanfogar slumpmässiga numret med strängen/fältvariabeln
    sprintf(clientId, "espId-%ld", rand);
    // om vi nu är ansluta, med vårt clientId
    if (client.connect(clientId))
    {
      // Skriver vi ut att vi är anslutna
      Serial.print(clientId);
      Serial.println(" ansluten");
      // Så nu följer vi denna topic.
      client.subscribe(minTopic);
    }
    else
    {
      // Annars skriver vi ut ett felmeddelande, med RC-värde.
      Serial.print("Misslyckades. RC=");
      Serial.print(client.state());
      Serial.println("Försöker igen om 5 sekunder... ");
      // Väntar 5 sekunder.
      delay(5000);
    }
  }
}

// Callback
// Standard för PubSubClient.h
void mqttCallback(char* topic, byte* message, unsigned int length) {
  Serial.print("Fick meddelande i ämnet: ");
  Serial.print(topic);
  Serial.print(". Meddelandet: ");
  String stMessage;
  
  for (int i = 0; i < length; i++)
  {
   // Går igenom alla tecken i meddelandet.
    Serial.print((char)message[i]);
    stMessage += (char)message[i];
  }
  // Skriver ut ny rad efter alla tecken skrivits ut
  Serial.println();
}

// Setup() är en del av arduinos språk.
// Den kör det som behövs först.
void setup()
{
  Serial.begin(115200);
  //randomSeed(analogRead(Analog0));
  srand(time(0));
  
  // En kort fördröjning
  delay(10);

  Serial.print("Ansluter till: ");
  Serial.println(SSID);

  // Anslut mot WiFi
  anslutWiFi();
  // Om loopen är färdig ska vi se detta
  Serial.print("Nu är vi anslutna mot WiFi: ");
  Serial.print(WiFi.localIP());
  Serial.print(" ");
  Serial.println(WiFi.macAddress());

  // Se våra variabler längst upp för värde.
  client.setServer(mqttServer, mqttPort);
  client.setCallback(mqttCallback);

  // Vi säger att LED-pin/head/GPIO skall vara en utgång (det vill säga den skickar spänning på begäran)
  pinMode(LEDPIN1, OUTPUT);
  // Samma gäller här
  pinMode(LEDPIN2, OUTPUT);
  // Vi säger att push knappen skall vara en ingång (det vill säga tar emot spänning på begäran)
  pinMode(pushButton, INPUT);
}

// Denna är ungefär som "main()"
// Den loopar i all evighet, eller tills vi stänger av arduino/ESP32
void loop() {
  // Sätter ett värde på den lägsta och den högsta talet vi vill ha för vår random funktion
  int lower = -30, upper = 30;
  // Skriver över värdet från tryck knappen till buttonValue som en integer
  int buttonValue = digitalRead(pushButton);

  // Detta är en if stats som kontroller att värdet bara skiskas en gång
  // Om buttonValue är inte lika med lastButton då...
  if(buttonValue != lastButton){
    // Om buttonValue är hög, det vill säga 1...
    if (buttonValue == HIGH){
      // Då ska vi ska vår radom funktion lotta ut ett nummer mellan -30 till 30
      num = (rand() % (upper - lower + 1)) + lower;
        // Om talet är mindre eller lika med -30 och midre än 0
        if (num >= -30 && num < 0){
            // LED1 lyser
            digitalWrite(LEDPIN1, HIGH);
            // Fördröjning på 2 sekunder
            delay(2000);
            // LED1 släks
            digitalWrite(LEDPIN1, LOW);
        }
        // Om talet är större eller lika med o och midre än eller lika med 30
        if (num >= 0 && num <= 30){
            // LED2 lyser
            digitalWrite(LEDPIN2, HIGH);
            // Fördröjning på 2 sekunder
            delay(2000);
            // LED2 släks
            digitalWrite(LEDPIN2, LOW);
        }
        // sprintf() används för att skriva en formaterad sträng till teckensträngsbuffert.
        sprintf(temp, "%d", num);
        // Skickar topicen och temperatur värdet som ett meddelande till subClienten
        client.publish(minTopic, temp);
    
    }
    // En kort fördröjning, så att ESP:n blir "utmattad"
    delay(50);
  }
  
  // lastButton = buttonValue
  lastButton = buttonValue;

  // Om vår klient inte är ansluten till MQTT.. SÅ
  if (!client.connected())
  {
    // Anropar vår återanslutningsfunktion.
    mqttAteranslut();
  }

  // Ungefär samma som loop(), bara det att vi loopar MQTT.
  // ALLT vi har ställt in, hanterar denna (callback, inställningar som broker, port med mera.)
  client.loop();
}