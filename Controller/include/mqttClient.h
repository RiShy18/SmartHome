#ifndef _MQTT_H
#define _MQTT_H

#include <MQTTAsync.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <MQTTAsync.h>
#include <unistd.h>
#include <gpio.h>
#include <tools.h>

#define ADDRESS "tcp://192.168.0.169:1883"
#define CLIENTID "ClienteDePrueba"
#define TOPIC1 "luces/+"
#define TOPIC2 "camera"
#define TOPIC3 "puertas"
#define QOS 1
#define TIMEOUT 10000L
#define USERNAME "usuario"
#define PASSWORD "usuario"

void initMqtt(int *pins, int size);
void connlost(void *context, char *cause);
int msgarrvd(void *context, char *topicName, int topicLen, MQTTAsync_message *message);
void onDisconnect(void *context, MQTTAsync_successData *response);
void onSubscribe(void *context, MQTTAsync_successData *response);
void onSubscribeFailure(void *context, MQTTAsync_failureData *response);
void onConnectFailure(void *context, MQTTAsync_failureData *response);
void onConnect(void *context, MQTTAsync_successData *response);
void onSend(void *context, MQTTAsync_successData *response);
void sendMessage(char *payload, char *topic);
int split(char *str, char c, char ***arr);


#endif