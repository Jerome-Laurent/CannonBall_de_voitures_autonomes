#include <cstdio>
#include <cstring>
#include <iostream>

#include <stdint.h>
#include "mqtt_sender.h"

mqtt_sender::mqtt_sender(const char *id, const char *host, int port) : mosquittopp(id)
{
    int keepalive = 60;
    bool clean_session = true;

    /* Connect immediately. This could also be done by calling
     * mqtt_sender->connect(). */
    connect(host, port, keepalive);
};

void mqtt_sender::send_message(char *msg ) {
    std::cout << "Sending message.." << std::endl;
    publish(NULL, "hello/world", strlen(msg)*sizeof(uint8_t), (uint8_t *) msg); //Client
    std::cout << "Sent!" << std::endl;
}

void mqtt_sender::on_connect(int rc)
{
    printf("Connected with code %d.\n", rc);
    /*if(rc == 0){
        //Only attempt to subscribe on a successful connect.
        //subscribe(NULL, "temperature/celsius"); //Server
    }*/
}

void mqtt_sender::on_message(const struct mosquitto_message *message)
{
    /*
       double temp_celsius, temp_farenheit;
       char buf[51];

       if(!strcmp(message->topic, "temperature/celsius")){
       memset(buf, 0, 51*sizeof(char));
    // Copy N-1 bytes to ensure always 0 terminated.
    memcpy(buf, message->payload, 50*sizeof(char));
    temp_celsius = atof(buf);
    temp_farenheit = temp_celsius*9.0/5.0 + 32.0;
    snprintf(buf, 50, "%f", temp_farenheit);
    publish(NULL, "temperature/farenheit", strlen(buf), (uint8_t *)buf);
    }
    */
    printf("Message received.\n");
}

void mqtt_sender::on_subscribe(uint16_t mid, int qos_count, const uint8_t *granted_qos)
{
    printf("Subscription succeeded.\n");
}
