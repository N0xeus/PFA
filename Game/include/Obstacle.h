#ifndef OBSTACLE_H
#define OBSTACLE_H

////////////////////////////////////////////////////////////
// Header
////////////////////////////////////////////////////////////
#include <TouchableObject.h>

////////////////////////////////////////////////////////////
/// \brief Obstacle constrain Character to move correctly
///
////////////////////////////////////////////////////////////
class Obstacle : public TouchableObject
{
    public:
        ////////////////////////////////////////////////////////////
        /// \brief Constructor
        ///
        /// \param resistance Resistance against \link Character attack
        ///
        /// Create a \link TouchableObject with resistance
        ///
        /// \see Attack
        ///
        ////////////////////////////////////////////////////////////
        Obstacle(int id, const sf::IntRect box, int resistance);

        ////////////////////////////////////////////////////////////
        /// \brief Destructor
        ///
        ////////////////////////////////////////////////////////////
        virtual ~Obstacle();

        ////////////////////////////////////////////////////////////
        /// \brief Getter of current resistance
        ///
        /// \return Resistance
        ///
        ////////////////////////////////////////////////////////////
        int getRes(){ return res; }

        ////////////////////////////////////////////////////////////
        /// \brief Setter of current resistance
        ///
        /// \param New resistance
        ///
        ////////////////////////////////////////////////////////////
        void setRes(int val){ res=val; }

        ////////////////////////////////////////////////////////////
        /// \brief Getter of destruction property
        ///
        /// Return true if the object is destructible
        ///
        ////////////////////////////////////////////////////////////
        bool isDestructible(){ return destructible; }

        ////////////////////////////////////////////////////////////
        /// \brief Setter of destructible property
        ///
        /// \param New destruction property
        ///
        ////////////////////////////////////////////////////////////
        void setDestructible(bool b){ destructible=b; }

        ////////////////////////////////////////////////////////////
        /// \brief Determine the type of the object
        ///
        /// Return true if the object is an \link Attack
        ///
        ////////////////////////////////////////////////////////////
        bool isAttack(){ return false; }

        ////////////////////////////////////////////////////////////
        /// \brief Determine the type of the object
        ///
        /// Return true if the object is an \link Character
        ///
        ////////////////////////////////////////////////////////////
        bool isCharacter(){ return false; }

        ////////////////////////////////////////////////////////////
        /// \brief Determine the type of the object
        ///
        /// Return true if the object is an \link Obstacle
        ///
        ////////////////////////////////////////////////////////////
        bool isObstacle(){ return true; }

        ////////////////////////////////////////////////////////////
        /// \brief Determine the type of the object
        ///
        /// Return true if the object is an \link Pickable
        ///
        ////////////////////////////////////////////////////////////
        bool isPickable(){ return false; }

        ////////////////////////////////////////////////////////////
        /// \brief Determine if the object was destroyed
        ///
        /// Return true if there is not enough resistance
        ///
        ////////////////////////////////////////////////////////////
        bool wasDestroyed();

    protected:

    private:
        ////////////////////////////////////////////////////////////
        /// Member data
        ////////////////////////////////////////////////////////////
        int res;            /// Current resistance
        int resMax;         /// Resistance maximum
        bool destructible;  /// Destruction property, true if destructible
};

#endif // OBSTACLE_H