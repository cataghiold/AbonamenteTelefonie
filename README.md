# AbonamenteTelefonie

Folosind derivare, moșteniri, virtualizare și polimorfism să se implementeze un program care gestionează serviciile oferite de companie de telefonie mobilă.

Serviciile oferite sunt:

A – Abonament Standard. Costul abonamentului este de 50 lei. Abonamentul include 100 minute, 100 SMS și 10GB internet. Dacă sunt depășite cele 100 minute utilizatorul plătește 0.1 lei pe minut în plus consumat. Dacă sunt depășite mesajele, clientul plătește 0.5 lei pe SMS în plus. Dacă este depășită limita de internet, utilizatorul plătește 1 leu pentru fiecare GB în plus.

B – Abonament Standard Plus. Costul abonamnetului este de 75 lei. Abonamentul include 200 minute, 200 SMS și 15GB. Dacă sunt depășite cele 200 minute utilizatorul plătește 0.15 lei pe minut în plus consumat. Dacă sunt depășite mesajele, clientul plătește 0.75 lei pe SMS în plus. Dacă este depășită limita de internet, utilizatorul plătește 1.5 leu pentru fiecare GB în plus.

Clienții își achiziționează un abonament pe baza ID-ului propriu care este un număr pe 64 biți.

Din N înregistrări din gestiune, determinați ID-ul clientului care plătește cel mai mult pentru serviciile oferite. Un client poate avea unul sau mai multe abonamente de același fel sau diferite.

Sugestie de implementare:

Clasă de bază Servicii din care se derivează clasele pentru abonamente.



Date de intrare:

N – numărul de înregistrări pentru care se face analiza

ID_client Tip_Abonament Minute_folosite_total SMS_folosite_total GB_folosit total

Date de ieșire:

ID-ul clientului care plătește cel mai mult

 

Exemplu:

Intrare:

3

10 A 100 100 10

20 B 200 200 15

30 A 100 150 15

Ieșire:

30

 

Explicație:

Clientul cu ID 10 folosește doar ce este inclus deja in abonament deci plătește doar prețul abonamentului 50 lei

Clientul cu ID 20 folosește doar ce este inclus deja in abonament deci plătește doar prețul abonamentului de tip B 75 lei

Clientul cu ID 30 depășește ce este inclus în abonamentul de tip A astfel că acesta are de plată

50 + (150-100)*0.5 + (15-10)*1 =80 lei
