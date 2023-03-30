/// File: AnimatedWindow.h
/// Florida Gulf Coast University
/// Department of Software Engineering
/// created by pallen on 6/27/2022.
// ----------------------------------------------------------------------------
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "AnimatedShape.h"
#include <string>
#include <list>

#ifndef FGCU_ANIMATEDWINDOW_H
#define FGCU_ANIMATEDWINDOW_H

namespace fgcu {

    const int DEFAULT_FPS = 30;

    /// Window that can serve as a target for 2D drawing.
    ///
    /// fgcu::AnimatedWindow is the main class of the Eagles animation library.
    ///
    /// fgcu::AnimatedWindow is derived from sf::RenderWindow, thus it inherits all
    /// its features: events, window management, OpenGL rendering, etc. See the
    /// documentation of sf::RenderWindow for a more complete description of all
    /// these features, as well as code examples.
    ///
    /// fgcu::AnimatedWindow holds a collection of fgcu::AnimatedShape objects and
    /// manages updates to the objects on frame-boundaries, and rendering of objects
    /// based on current frame-times.
    class AnimatedWindow : public sf::RenderWindow {
    public:

        /// Create (or recreate) the window.
        ///
        /// If the window was already created, it closes it first. If style contains Style::Fullscreen, then mode must be a valid video mode.
        ///
        /// The fourth parameter is an optional structure specifying advanced OpenGL context settings such as antialiasing, depth-buffer bits, etc.
        /// \param width    Width of the window in pixels.
        /// \param height   Height of the window in pixels.
        /// \param title    Title of the window.
        /// \param style  	Window style, a bitwise OR combination of sf::Style enumerators.
        /// \param settings Additional settings for the underlying OpenGL context.
        AnimatedWindow(unsigned int width, unsigned int  height, std::string title, sf::Uint32 style = sf::Style::Default, const sf::ContextSettings& settings = sf::ContextSettings());

        /// Create (or recreate) the window.
        ///
        /// If the window was already created, it closes it first. If style contains Style::Fullscreen, then mode must be a valid video mode.
        ///
        /// The fourth parameter is an optional structure specifying advanced OpenGL context settings such as antialiasing, depth-buffer bits, etc.
        /// \param width    Width of the window in pixels.
        /// \param height   Height of the window in pixels.
        /// \param title    Title of the window.
        /// \param style  	Window style, a bitwise OR combination of sf::Style enumerators.
        /// \param settings Additional settings for the underlying OpenGL context.
        void create(unsigned int width, unsigned int  height, std::string& title, sf::Uint32 style = sf::Style::Default, const sf::ContextSettings& settings = sf::ContextSettings());

        /// Deletes pointers to fgcu::AnimatedShape objects added to its collection.
        ~AnimatedWindow();

        /// Set the background color of the window.
        /// \param color integer in format RedGreenBlueAlpha (example in hex 0xFF7550FF is Coral Blue (255,127,80).
        void setColor(unsigned int color);

        /// Set the background color of the window.
        /// \param color A valid sf::Color constant or class instance.
        void setColor(sf::Color color);

        /// Get the current background color of the window.
        /// \return a sf::Color instance.
        sf::Color getColor() const;

        /// Set the frames-per-second rate for animations.
        /// \param fps Frames-per-second (default is 30).
        void setFPS(int fps);

        /// Get the current frames-per-second rate of the window.
        /// \return Current frames-per-second rate.
        int getFPS() const;

        /// Add a shape to the shapes collection.
        /// \param shape Pointer to an fgcu::AnimatedShape .
        /// \return index of the shape in the collection.
        unsigned int addShape(AnimatedShape* shape);

        /// Removes a shape from the shapes collection.
        /// \param index The index of the shape in the collection.
        /// \return A pointer to the shape object removed.
        AnimatedShape* removeShape(unsigned int index);

        /// Process animation frames. Renders objects in the shapes collection
        /// relative to their postion by speed and time, and updates shape location
        /// on frame boundaries.
        /// \return False if the window close event has been received.
        bool nextFrame();

        /// Get the last key entered on the keyboard.
        /// \return A SFML key code.
        sf::Keyboard::Key getLastKey();

        /// Reset the animation timer.
        void timerReset();

    protected:
        std::list<fgcu::AnimatedShape*> m_shapes;

        sf::Color m_color;

        sf::Clock m_timer;
        int m_fps;
        float m_lag;

        sf::Keyboard::Key m_lastKey;

    private:
        sf::Time p_startTime;
        sf::Time p_stopTime;

        unsigned int p_shapeIndex;

    };

} // fgcu

#endif //FGCU_ANIMATEDWINDOW_H
