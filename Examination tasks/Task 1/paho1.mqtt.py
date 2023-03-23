# Vi importerar paho.mqtt.client som mqtt för det blir tok för långt att skriva paho.mqtt.client 
# varje gång vi vill anropa det.
import paho.mqtt.client as mqtt
# #include <paho.mqtt.client>

# Den här variabeln använder vi längre ner, tillsammans med "client.connect"
# Så vi gör först vår inställning (enklast att se)
# Byter vi till en annan så kan vi enkelt ändra det här.
# 127.0.0.1 = Den som kör programmets lokala dator
MQTT_SERVER = "test.mosquitto.org"

# Så kalla "callback" 
def on_connect(client, userdata, flags, rc):
    # str(rc) menas att vi konverterar RC till en sträng (inte säkert att den är det)
    print("Ansluten: " + str(rc))

    # Ligger i on_connect för att om vi tappar anslutning
    # så kommer den förnyas när den återansluter.
    client.subscribe("Belal.Almshmesh/pushButton35")

# När servern fått PUBLISH kommer det genom denna callback
def on_message(client, userdata, msg):
    print(msg.topic + " " + str(msg.payload))

# initierar client med mqtt.Client (stort C)
client = mqtt.Client()
# Säger åt clienten vart vi har våra callbacks
client.on_connect = on_connect
client.on_message = on_message
# Anslut till en broker
client.connect(MQTT_SERVER, 1883, 60)

# Nu säger vi åt clienten att loopa i all evighet (eller tills vi stänger ner programmet)
# Som en while True:
client.loop_forever()