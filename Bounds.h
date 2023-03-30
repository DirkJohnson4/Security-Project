/// File: Bounds.h
/// Florida Gulf Coast University
/// Department of Software Engineering
/// created by pallen on 6/27/2022.
// ----------------------------------------------------------------------------
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>

#ifndef FGCU_BOUNDS_H
#define FGCU_BOUNDS_H

namespace fgcu {

    /// A utility class used to calculate and align bounding rectangles relative to other rectangles.
    ///
    /// A bounding rectangle is defined by a set of properties (left,top) and (width,height).
    /// Other properties can be calculated as:
    /// right = left + width
    /// bottom = top + height
    /// center = left + width / 2
    /// middle = top + height / 2
    ///
    /// The screen (x,y) location used to position the rectangle may be the (left,top) or may be adjusted by origin properties that provide offsets to the (x,y) properties.
    class Bounds {
    public:
        /// Construct a bounding rectangle.
        /// \param bounds The width and height of the rectangle.
        /// \param position The (x,y) position of the rectangle.
        Bounds(sf::FloatRect bounds, sf::Vector2f position);

        /// Set the left of the bounding rectangle to the left of the other bounding rectangle provided.
        /// \param other The other bounding rectangle
        void alignLeft(fgcu::Bounds& other);

        /// Set the horizontal center of the bounding rectangle to the horizontal center of the other bounding rectangle provided.
        /// \param other The other bounding rectangle
        void alignCenter(fgcu::Bounds& other);

        /// Set the right of the bounding rectangle to the right of the other bounding rectangle provided.
        /// \param other The other bounding rectangle
        void alignRight(fgcu::Bounds& other);

        /// Set the top of the bounding rectangle to the top of the other bounding rectangle provided.
        /// \param other The other bounding rectangle
        void alignTop(fgcu::Bounds& other);

        /// Set the vertical middle of the bounding rectangle to the middle of the other bounding rectangle provided.
        /// \param other The other bounding rectangle
        void alignMiddle(fgcu::Bounds& other);

        /// Set the bottom of the bounding rectangle to the bottom of the other bounding rectangle provided.
        /// \param other The other bounding rectangle
        void alignBottom(fgcu::Bounds& other);

        /// Adjust the rectangle so that it would be left of other rectangle: left = other.left - width - padding
        /// \param other The other bounding rectangle
        /// \param padding Additional distance to move this rectangle. Default = 0.
        void toLeftOf(fgcu::Bounds& other, float padding=0.0);

        /// Adjust the rectangle so that it would be right of other rectangle: left = other.right + padding
        /// \param other The other bounding rectangle
        /// \param padding Additional distance to move this rectangle. Default = 0.
        void toRightOf(fgcu::Bounds& other, float padding=0.0);

        /// Adjust the rectangle so that it would be above of other rectangle: top = other.top - height - padding
        /// \param other The other bounding rectangle
        /// \param padding Additional distance to move this rectangle. Default = 0.
        void toTopOf(fgcu::Bounds& other, float padding=0.0);

        /// Adjust the rectangle so that it would be below of other rectangle: top = other.bottom + padding
        /// \param other The other bounding rectangle
        /// \param padding Additional distance to move this rectangle. Default = 0.
        void toBottomOf(fgcu::Bounds& other, float padding=0.0);

        /// Get the (x,y) coordinate on the other rectangle that is closest to a point on this rectangle, either (left,top) or (center,middle).
        /// \param other The other bounding rectangle .
        /// \param fromCenter True if point should be from the center of this rectangle, false for (left,top).
        /// \return The closest point on the other rectangle.
        sf::Vector2f closestPoint(fgcu::Bounds& other, bool fromCenter=true);

        /// Linear distance between a point on this rectangle, and the closet point on the other.  Uses the closestPoint function in this class.
        /// \param other The other bounding rectangle.
        /// \param fromCenter True if point should be from the center of this rectangle, false for (left,top).
        /// \return The distance between points on the two bounding rectangles.
        float distanceToClosestPoint(fgcu::Bounds& other, bool fromCenter=true);

        /// Angle between this rectangle and the closet point on the other bounding rectangle. Uses the closestPoint function in this class.
        /// \param other The other bounding rectangle.
        /// \param fromCenter True if point should be from the center of this rectangle, false for (left,top).
        /// \return The angle between points on the two bounding rectangles in degrees (0-359, North=0).
        float angleToClosestPoint(fgcu::Bounds& other, bool fromCenter=true);

        float x;        /// The screen x coordinate.
        float y;        /// The screen y coordinate.
        float originX;  /// The origin x coordinate.
        float originY;  /// The origin y coordinate.
        float width;    /// The width of the bounding rectangle.
        float height;   /// The height of the bounding rectangle.
        float left;     /// The screen left side x value.
        float right;    /// The screen right side x value
        float top;      /// The screen top side y value.
        float bottom;   /// The screen bottom side y value.
        float center;   /// The screen horizontal center x value.
        float middle;   /// The screen vertical middle x value.
    };

} // fgcu

#endif //FGCU_BOUNDS_H
