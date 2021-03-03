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
e l'altro entra nel secondo mezzo variando la sua direzione di propagazione, cioè viene rifratto<br>
<hr>
