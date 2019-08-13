This tutorial will show how to set up a MQTT broker on an Open-WRT router. My reason for this is that I am running my own network segment in my apartment so I can run network experiments without worrying about intruding on my flatmates. Also for my privacy since I don't want them snooping on me either.  

I've been wanting to explore further IoT methods and I"ve been interested in the MQTT protocol, Message Queuing Telemetry Transport. MQTT is a communicaton protocol for small sensors and devices optimized for high-latency or unreliable networks. For this reason it is a great protocol for IoT devices.

## How MQTT operates in a nutshell
MQTT requires a client and a broker. MQTT clients are both subscribers and publishers. The broker is responsible for receiving all messages, filtering the messages, and determining who is subscribed to the message and sends on the messagse to the subscribed clients. 

## Installing Mosquitto Broker 
As described earlier, to use the MQTT protocol you need a broker. There are a number of MQTT broker options, including cloud based and local. I am a big fan of keeping things inhouse so I chose an open source MQTT broker called Mosquitto to run locally. I decided to set up my broker my Open-WRT router since I figured why not, the openwrt is already switching tcp, it might as well switch mqtt.

On the router you can run:
1. `opkg update`
2. `opkg install mosquitto mosquitto-client libmosquitto`

Begin mosquitto with: 
1. `/etc/init.d/mosquitto enable`
2. `/etc/init.d/mosquitto restart`

Create user and add password:
* `mosquitto_passwd -c /etc/mosquitto/passwd <username>

Edit your mosquitto configuration file with your favorite editor.
* `vim /etc/mosquitto/mosquitto.conf` 
* `allow_anonymouse false`
* `password_file /etc/mosquitto/passwd`
* `/etc/init.d/mosquitto restart`

Now you can open two sessions on your router and on one session you can subscribe to a topic with:
` mosquitto_sub -h localhost -t test -u "<user>" -P "<passphrase>"`

and on another session you can enter
`mosquitto_pub -h localhost -t "test" -u "<user>" -P "<passphrase>"`

You should see be able to see the message passed to your first session. 

## Connecting to broker with ESP-8266
These steps assume you know how to connect to a network with ESP 8266.  We'll be using the PubSubClient library to connect to the broker and pub/sub messages in topics. 

To connect to the mqtt server:
```
const char* mqttServer="<ip address of router>";
const int mqttPort=1883; // default is 1883
const char* mqttUser="<mqtt username>"";
const char* mqttPass="<passphrase>";
```

We'll declare a WiFiClient which allws a connection to a specified IP and port, and declare a PubSubClient object that takes the wificlient as the input.

```
WiFiClient espClient;
PubSubClient client(espClient);
```

You'll need to specify the address and port of the MQTT server using the setServer method and use the setCallback method to specify a handling function when a message is received.

mqtt connection snippet:
```
client.setServer(mqttServer, mqttPort);
client.setCallback(callback);

while(!client.connected()){

    Serial.println("Connecting to mosquitto...");
    if(client.connect("ESP8266Client", mqttUser, mqttPass)){
        Serial.println("Connected to mosquitto.");
    } else {
        Serial.print("Failed with State ");
        Serial.print(client.state());
        delay(1000);
    }
}
```

After connecting to the MQTT broker you can publish and subscribe to topics using the PubSubClient method publish and subscribe: 
```
client.publish("esp/test", "Hello from a little device");
client.subscribe("esp/test");
```

 Your callback that handles messages when received by client looks like: 
 ```
 void callback(char* topic, byte* payload, unsigned int length){
    Serial.println("##########");
    Serial.print("Message arrived in topic: ");
    Serial.println(topic);

    Serial.print("Message: ");
    for(int i = 0; i< length; i++){
        Serial.print((char)payload[i]);
    }

    Serial.println();
    Serial.println("##########");
}```

Your loop will call the loop method of the PubSubClient. This will allow the client to pass incoming messagse and maintain its connection.
```
void loop() {
  client.loop();
}
```

Now you can communicate between your open-wrt mosquitto broker and your esp8266 device.
