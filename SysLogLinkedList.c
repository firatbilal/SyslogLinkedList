#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node yap�s�n� tan�ml�yoruz, her d���m bir veri ve bir sonraki d���me i�aret�i i�erir
typedef struct Node {
    char *data; // Syslog sat�r�n� tutan veri
    struct Node *next; // Bir sonraki d���me i�aret�i
} Node;

// Yeni bir d���m olu�turur ve veri ile ba�lat�r
Node* createNode(char *data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Ba�l� listenin sonuna yeni bir d���m ekler
void append(Node **head, char *data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Belirtilen syslog dosyas�n� okur ve sat�rlar� ekrana yazd�r�r
void readSyslogFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Syslog dosyasi acilamadi");
        return;
    }
    
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}

// Syslog dosyas�n� okur ve her sat�r� ba�l� listeye ekler
void processSyslogData(Node **head, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Syslog dosyasi acilamadi");
        return;
    }
    
    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, file) != -1) {
        char *data = strdup(line);
        append(head, data);
    }

    free(line);
    fclose(file);
}

// Ba�l� listedeki t�m d���mleri ve verilerini yazd�r�r
void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%s", temp->data);
        temp = temp->next;
    }
}

int main() {
    Node *head = NULL;

    const char *syslogFile = "/var/log/syslog"; // Syslog dosyas�n�n yolu
    processSyslogData(&head, syslogFile);
    
    printf("Bagli Listedeki Syslog Verileri:\n");
    printList(head);

    return 0;
}

