# Bluetooth_IR_Repeater
# NE İŞE YARAR?
İstediğiniz herhangibir kızılötesi kumandayı telefon uygulaması ile koplayarak taklit edebilmenizi sağlar. Bu proje ile televizyonunuza bir akıllı kumanda yapabilirsiniz. Bu sayede televizyon fonksiyonlarını akıllı telefonlar ile sağlayabilirsiniz. 

# NASIL ÇALIŞIR?
Öncelikle uygulamayı bluetooth üzerinden bağlıyoruz. Daha sonra uygulamadaki "Teach Mode"
tikini aktif ediyoruz. Hemen ardından alıcıya kopyalayacağımız tuşu okutuyoruz. Bu okunan kumanda kodunu uygulamadan 
hangi tuşa atamak istiyorsak o tuşa basıyoruz ve artık uygulamadaki atanan tuşa bastığımızda 
okuttuğumuz kumanda kodu taklid edilecektir. Uygulama üzerinde 14 adet atanabilir tuş bulunmaktadır. 3 çizgi ile
gösterilen tuş bluetooth cihazlarını görüntülemektedir. Uygulamanın APK'sı ve  APP inventor çalışma dosyası bulunmaktadır.
isteğinize uygun olarak geliştirebilirsiniz.

# NOT
Okutulan kumanda kodları program içerisinde uygun EEPROM adreslerine kaydedilmektedir. Yani cihaz kapatılıp açılsa dahi okutulan ve atanan tuşlar Arduino hafızasında tutulmaktadır. Daha önce okutulmuş bir kod yerine yenisini okutursanız uygulamadaki o tuşa ait kumanda kodu silinir ve yeni okutulan kumanda kodu kaydedilir.

# IRremote kütüphanesi linki
https://github.com/z3t0/Arduino-IRremote

# UYARI!
Eğer linkteki kütüphaneyi yükledikten sonra hata alıyorsanız onun yerine dosyalar içerisindeki "IRremote" isimli kütüphaneyi kurunuz. Bu kütüphane linkteki kütüphanenin daha eski bir sürümüdür.

# Bluetooth modülü ayarlarını yapmak için
https://maker.robotistan.com/hc05-hc06-bluetooth-uart-modulleri-kullanimi/

Kendi yaptığım devreme ait fotoğrafları, devre şemasını, uygulama APK'sı, uygulama düzenleme dosyasını ve tüm kodları dosyanın içerisinde bulabilirsiniz. Herkese iyi çalışmalar dilerim.

# SOSYAL MEDYA HESAPLARIM
# İnstagram 
https://www.instagram.com/bahaerden/
# Facebook
https://www.facebook.com/baha.erden.12
