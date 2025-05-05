# 243-421-H25_TP6
Projet banc connecté

## Matériel  
- Plaquette de développement du banc connecté Humanity tech incluant :
  - 1 carte [NodeMcu](https://fr.wikipedia.org/wiki/NodeMCU)
  - 2 bandes lumineuses  
  - 1 capteur de proximité et luminosité APDS-9930 de [Avago](https://www.broadcom.com/products/sensors/optical-sensors/proximity-sensors/apds-9930)
  - 1 chargeur de téléphone par induction  
  - 1 écran LCD OLED
 
## Fonctionnement attendu  

**Le chargeur par induction** est fonctionnel dès qu’il est alimenté par son port USB. Le microcontrôleur n’a pas le pouvoir d’arrêter la charge, il peut uniquement détecter si du courant est fourni par le chargeur par induction. Pour savoir s’il fournit du courant, le microcontrôleur doit lire le niveau de tension au diviseur de tension.

**Le capteur de proximité et de luminosité** est utilisé pour détecter la présence d’un utilisateur et pour détecter le niveau de luminosité.

**Les bandes de DEL** indiquent si le chargeur par induction est présentement en utilisation.  
Les **DELs** sont toutes rouges lorsqu’un appareil est en charge, autrement les **DELs** sont toutes jaunes.  
S’il fait sombre, l’intensité lumineuse doit être abaissée pour ne pas aveugler les utilisateurs.

**L’écran** affiche le nombre de présences détectées et le nombre de téléphones chargés.
