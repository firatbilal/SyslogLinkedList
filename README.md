# Syslog Veri İşleme ve Bağlı Liste Yönetimi

Bu proje, bir syslog dosyasını okuyarak her satırı bağlı listeye ekleyen ve ardından bu verileri ekrana yazdıran bir C programıdır. Program, log verilerini işleyerek bağlantılı liste veri yapısında saklar ve bu yapıdaki verileri sıralı olarak çıktı verir. Syslog dosyalarını analiz etme, işleme ve izleme amacıyla kullanılabilecek bir araçtır.

## İçindekiler
- [Kurulum](#kurulum)
- [Kullanım](#kullanım)
- [Fonksiyonlar](#fonksiyonlar)
- [Katkıda Bulunanlar](#katkıda-bulunanlar)

## Kurulum

1. Bu repoyu klonlayın:
    ```bash
    git clone https://github.com/firatbilal/SyslogLinkedList
    ```
2. Derleyici ile kodu derleyin:
    ```bash
    gcc -o SysLogLinkedList SysLogLinkedList.c
    ```

## Kullanım

1. Programı çalıştırın:
    ```bash
    ./SysLogLinkedList
    ```
2. Varsayılan olarak `/var/log/syslog` dosyasını okuyacaktır. Dosya yolu ve diğer parametreleri değiştirerek farklı kullanım senaryoları oluşturabilirsiniz.

## Fonksiyonlar

- **createNode**: Yeni bir düğüm oluşturur ve veri ile başlatır.
- **append**: Bağlı listenin sonuna yeni bir düğüm ekler.
- **readSyslogFile**: Belirtilen syslog dosyasını okur ve satırları ekrana yazdırır.
- **processSyslogData**: Syslog dosyasını okur ve her satırı bağlı listeye ekler.
- **printList**: Bağlı listedeki tüm düğümleri ve verilerini yazdırır.

## Katkıda Bulunanlar

- [firatbilal](https://github.com/firatbilal)
