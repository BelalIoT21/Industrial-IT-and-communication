# Vi importerar paho.mqtt.client som mqtt för det blir tok för långt att skriva paho.mqtt.client 
# varje gång vi vill anropa det.
import paho.mqtt.client as mqtt
import socket
# #include <paho.mqtt.client>

# Den här variabeln använder vi längre ner, tillsammans med "client.connect"
# Så vi gör först vår inställning (enklast att se)
# Byter vi till en annan så kan vi enkelt ändra det här.
MQTT_SERVER = "test.mosquitto.org"
VM_SERVER = "192.168.0.37"

# receive 4096 bytes each time
BUFFER_SIZE = 4096

# Så kalla "callback" 
def on_connect(client, userdata, flags, rc):
    # str(rc) menas att vi konverterar RC till en sträng (inte säkert att den är det)
    print("Ansluten: " + str(rc))

    # Ligger i on_connect för att om vi tappar anslutning
    # så kommer den förnyas när den återansluter.
    client.subscribe("Belal.Almshmesh/LED_pushButton_Temp")

# När servern fått PUBLISH kommer det genom denna callback
def on_message(client, userdata, msg):
    nytext = msg.payload
    # skickar meddlandet som vi har fått till en annan sever som en ny text
    s.send(nytext)
    # skriver ut topicen och meddelandet som vi har fått
    print(msg.topic + " " + str(msg.payload))

# initierar client med mqtt.Client (stort C)
client = mqtt.Client()
# Säger åt clienten vart vi har våra callbacks
client.on_connect = on_connect
client.on_message = on_message
# Anslut till en broker
client.connect(MQTT_SERVER, 1883, 60)
 # create the client socket
s = socket.socket()
s.connect((VM_SERVER, 5001))

# Nu säger vi åt clienten att loopa i all evighet (eller tills vi stänger ner programmet)
# Som en while True:
client.loop_forever()

# close the client socket
client_socket.close()
# close the server socket
s.close()