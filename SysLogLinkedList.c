#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node yapýsýný tanýmlýyoruz, her düðüm bir veri ve bir sonraki düðüme iþaretçi içerir
typedef struct Node {
    char *data; // Syslog satýrýný tutan veri
    struct Node *next; // Bir sonraki düðüme iþaretçi
} Node;

// Yeni bir düðüm oluþturur ve veri ile baþlatýr
Node* createNode(char *data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Baðlý listenin sonuna yeni bir düðüm ekler
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

// Belirtilen syslog dosyasýný okur ve satýrlarý ekrana yazdýrýr
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

// Syslog dosyasýný okur ve her satýrý baðlý listeye ekler
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

// Baðlý listedeki tüm düðümleri ve verilerini yazdýrýr
void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%s", temp->data);
        temp = temp->next;
    }
}

int main() {
    Node *head = NULL;

    const char *syslogFile = "/var/log/syslog"; // Syslog dosyasýnýn yolu
    processSyslogData(&head, syslogFile);
    
    printf("Bagli Listedeki Syslog Verileri:\n");
    printList(head);

    return 0;
}

