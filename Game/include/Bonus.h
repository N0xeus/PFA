#ifndef BONUS_H
#define BONUS_H

////////////////////////////////////////////////////////////
// Header
////////////////////////////////////////////////////////////
#include <Pickable.h>

////////////////////////////////////////////////////////////
/// \brief Bonus pickable
///
////////////////////////////////////////////////////////////
class Bonus : public Pickable
{
    public:
        ////////////////////////////////////////////////////////////
        /// \brief Constructor
        ///
        /// Create an \link Pickable which is a bonus
        ///
        ////////////////////////////////////////////////////////////
        Bonus(int id, const sf::FloatRect box);

        ////////////////////////////////////////////////////////////
        /// \brief Destructor
        ///
        ////////////////////////////////////////////////////////////
        virtual ~Bonus();

        ////////////////////////////////////////////////////////////
        /// \brief Determine the Pickable type
        ///
        /// Return true if the Pickable is a Bonus
        ///
        ////////////////////////////////////////////////////////////
        bool isBonus(){ return true; }

        ////////////////////////////////////////////////////////////
        /// \brief Determine the Pickable type
        ///
        /// Return true if the Pickable is a Life
        ///
        ////////////////////////////////////////////////////////////
        bool isLife(){ return false; }

    protected:

    private:
};

#endif // BONUS_H
