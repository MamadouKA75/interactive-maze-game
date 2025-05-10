#ifndef VOITURE_H
#define VOITURE_H

/**
 * @brief La classe Voiture représente une voiture dans un jeu de course de voiture 2D.
 */
class Voiture {
    private:
        float vitesse; /**< La vitesse actuelle de la voiture */
        float angle; /**< L'angle de la direction dans laquelle la voiture se déplace */
        // Ajoutez d'autres variables membres nécessaires ici
        
    public:
        /**
         * @brief Constructeur de la classe Voiture.
         * @param vitesseInitiale La vitesse initiale de la voiture.
         * @param angleInitial L'angle initial de la direction dans laquelle la voiture se déplace.
         */
        Voiture(float vitesseInitiale, float angleInitial);
        // Ajoutez d'autres constructeurs si nécessaire
        
        /**
         * @brief Accélère la voiture.
         * @param increment L'incrément de la vitesse.
         */
        void accelerer(float increment);
        
        /**
         * @brief Freine la voiture.
         * @param decrement Le décrément de la vitesse.
         */
        void freiner(float decrement);
        
        /**
         * @brief Tourne la voiture.
         * @param angle L'angle de la direction dans laquelle la voiture doit se déplacer.
         */
        void tourner(float angle);
        // Ajoutez d'autres fonctions membres nécessaires ici
        
        // Accesseurs et mutateurs
        /**
         * @brief Renvoie la vitesse actuelle de la voiture.
         * @return La vitesse actuelle de la voiture.
         */
        float getVitesse() const;
        
        /**
         * @brief Modifie la vitesse actuelle de la voiture.
         * @param nouvelleVitesse La nouvelle vitesse de la voiture.
         */
        void setVitesse(float nouvelleVitesse);
        
        /**
         * @brief Renvoie l'angle de la direction dans laquelle la voiture se déplace.
         * @return L'angle de la direction dans laquelle la voiture se déplace.
         */
        float getAngle() const;
        
        /**
         * @brief Modifie l'angle de la direction dans laquelle la voiture se déplace.
         * @param nouvelAngle Le nouvel angle de la direction dans laquelle la voiture doit se déplacer.
         */
        void setAngle(float nouvelAngle);
        
};

#endif
