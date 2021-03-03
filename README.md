# MINI_RT
Il ray tracing (o dei raggi traccianti).<br>
Si tratta di un algoritmo tra i più usati nel settore della Grafica 3D (Videoludico e Cinematografico), <br>
ideato ormai diversi anni fa, con lo scopo di realizzare scene al computer con caratteristiche e<br>
proprietà il più possibile realistiche. Perciò, si può definire ray tracing il procedimento che genera <br>
in modo bidimensionale una scena tridimensionale, descritta mediante funzioni cosiddette primitive, <br>
come triangoli, cubi, sfere e coni, con una qualità descrittiva elevata, mediante la simulazione dell’interazione fra luce ed oggetti.<br>
<hr>
Alla base dell’algoritmo vi è un criterio elementare: per ogni punto appartenente ad un oggetto vengono<br>
generati i raggi relativi alle sorgenti luminose, creando un gioco di riflessioni e rifrazioni con i raggi<br>
provenienti da altri punti ed oggetti, che determinano le proprietà dei pixel (o punti) dell’immagine da<br>
visualizzare. Si può facilmente intuire come una tecnica tanto semplice richieda al tempo stesso una potenza<br>
di elaborazione notevole, in quanto anche in presenza di scene non complesse il numero di raggi da calcolare è elevatissimo.<br>
<hr>
<h3>Differenza tra riflessione e rifrazione</h3>
La riflessione e la rifrazione della luce si possono spiegare utilmente supponendo che la luce si propaghi sotto forma<br>
di raggi rettilinei (ottica geometrica). Quando un raggio di luce che viaggia in un mezzo materiale <br>
trasparente - come, per esempio, l'aria - incontra una superficie di separazione con un altro mezzo<br>
trasparente - per esempio, l'acqua - si divide normalmente in due raggi: uno viene riflesso dalla superficie<br>
e l'altro entra nel secondo mezzo variando la sua direzione di propagazione, cioè viene rifratto<br><br>
La rifrazione è la deviazione che un raggio luminoso subisce nel passare da un mezzo trasparente a un<br>
altro, per la differenza della velocità di propagazione nei due mezzi, ma questo é dipeso dalla densitá dei due corpi.<br>
<hr>
La legge della rifrazione stabilisce che l'angolo di incidenza e l'angolo di rifrazione giacciono sullo <br>
stesso piano e sono legati tra loro dalla relazione:n1 sen i = n2 sen rdove n1 e n2 sono gli indici di rifrazione assoluti dei due mezzi.<br>
<hr>
La riflessione avviene mediante la superficie di un corpo riflettente detto specchio, sembra che all'interno di esso ci sia un<br>
punto luminoso ma in realtá é soltanto un'immagine dell'oggetto prodotta dalla riflessione della luce emessa dal corpo<br>
<hr>
<h3>Le basi per capire il ray tracing</h3>
<br><b>SCENE</b><br>
É una collezione di oggetti e di sorgenti luminose visualizzabili da una telecamera detta osservatore <br>
<br><b>OBJECTS</b><br>
Un oggetto é un qualsiasi elemento dalla scena, nonostante il ray tracing possa elaborare solo oggetti<br>
matematicamente descrivibili (Sfera, cilindro, cono e piano) possiamo<br>
conmbinarli tra loro per sviluppare oggetti piú compressi, inoltre ognuno di<br>
essi ha caratteristiche quali : colore, lucentezza e rugositá.<br>
<br><b>LIGHT SOURCES</b><br>
Sono elementi che emettono sorgenti luminose in qualunque punto della scena<br>
 dopo aver individuato la posizione, va stabilita l'intensitá del raggio.<br>
<br><b>CAMERA</b><br>
E'il punto di osservazione della scena, similmente ad una fotocamera che per scattare<br>
 una foto ad un determinato oggetto necessita di luce.<br>
<br><b>RAY CASTING</b><br>
Si tratta di un metodo nel quale le superfici visibili degli oggetti <br>
 vengono colpiti dai raggi di luce dall'osservatore della scena<br>
 paragoniamo che la pellicola é come se fosse lo schermo del pc<br>
 l'obiettivo é l'occhio dell'osservatore, l'unitá piú piccola di luce<br>
 é detta pixel, che puó assumere forme circolari ed ellissoidali.<br>
 Le risoluzioni odierne sono molto piú prestanti, a ciascun pixel é<br>
 possibile associare un solo colore nell'unitá di tempo e nel ray tracing<br>
 esso rappresenta il colore della luce che passando sull'oggetto, attraversa<br>
 il pixel stesso fino a farlo arrivare all'occhio.
<br><b>RAY</b><br>
Sono sottili linee che determinano quali oggetti saranno visualizzati e come saranno visualizzati<br>
<br><b>RAYTRACING</b><br>
Rispetto al ray casting che si preoccupa di determinare solo quali siano le superfici<br>
visibili degli oggetti, il ray tracing estende tale valutazione cercando di stabilire<br>
come debbano apparire le superfici stesse. I programmi di ray tracing consentono infatti<br>
all’utente di impostare diversi effetti per rendere maggiormente realistichele immagini, come ombre,<br>
trasparenze e riflessioni, che sarebbero difficilmente ottenibili applicando altri metodi.<br>
<br><b>REFLECTION</b><br>
Se la superficie colpita dal raggio luminoso è riflettente, come uno specchio, il ray tracer <br>
deve determinare il colore in quel punto, tenendo conto non solo del colore della superficie, ma anche<br>
dei colori degli oggetti che si riflettono nel punto stesso.<br>
<br><b>TRASPARENCY</b><br>
Il ragionamento relativo alla trasparenza è simile a quello appena descritto per la riflessione,<br>
con la differenza fondamentale che il raggio attraversa in parte la superficie del corpo trasparente<br>
uscendone poi inclinato secondo il principio della rifrazione.<br>
Un tipico esempio di rifrazione è quello che consiste nell’introdurre una penna in un bicchiere d’acqua:<br>
osservando il bicchiere dall’alto la penna apparirà come piegata nella zona in cui si immerge nell’acqua stessa.<br>
