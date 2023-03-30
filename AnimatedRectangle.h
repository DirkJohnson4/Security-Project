/// File: AnimatedRectangle.h
/// Florida Gulf Coast University
/// Department of Software Engineering
/// created by pallen on 6/27/2022.
// ----------------------------------------------------------------------------
#include "AnimatedShape.h"

#ifndef FGCU_ANIMATEDRECTANGLE_H
#define FGCU_ANIMATEDRECTANGLE_H

namespace fgcu {

    /// A 4 sided shape with 2 equal length sides by width and 2 equal length sides by height.
    ///
    /// fgcu::AnimatedRectangle extends fgcu::AnimatedShape which provides for animation speeds and visibility, and gets all properties and methods of a sf::Shape.
    class AnimatedRectangle : public fgcu::AnimatedShape {
    public:
        /// Construct a rectangle given width and height float values.
        /// \param width The horizontal width of the shape.
        /// \param height The vertical height of the shape.
        explicit AnimatedRectangle(float width, float height);

        /// Construct a rectangle given width and height values as an (x,y) pair of floats in a sf::Vector2f structure.
        /// \param size The horizontal width and vertical height as an (x,y) pair of floats in a sf::Vector2f structure.
        explicit AnimatedRectangle(const sf::Vector2f& size = sf::Vector2f(0, 0));

        /// Alter the size of a rectangle given width and height float values.
        /// \param width The horizontal width of the shape.
        /// \param height The vertical height of the shape.
        void setSize(float width, float height);

        /// Alter the size of a rectangle given width and height values as an (x,y) pair of floats in a sf::Vector2f structure.
        /// \param size The horizontal width and vertical height as an (x,y) pair of floats in a sf::Vector2f structure.
        void setSize(const sf::Vector2f& size);

        /// Get the horizontal width of the rectangle.
        /// \return The horizontal width of the rectangle.
        float getWidth() const;

        /// Get the vertical height of the rectangle.
        /// \return The vertical height of the rectangle.
        float getHeight() const;

        /// Get the width and height of the rectangle as an (x,y) pair of floats in a sf::Vector2f structure.
        /// \return The width and height of the rectangle as an (x,y) pair of floats in a sf::Vector2f structure.
        const sf::Vector2f& getSize() const;

        /// Overrides base interface sf::Drawable::getPointCount.
        /// \return The number of points of the shape object.
        std::size_t getPointCount() const override;

        /// Overrides base interface sf::Drawable::getPoint.
        /// \param index The index number of the point on the shape.
        /// \return An (x,y) point location.
        sf::Vector2f getPoint(std::size_t index) const override;

    private:
        sf::Vector2f m_size;
    };

} // fgcu

#endif //FGCU_ANIMATEDRECTANGLE_H
