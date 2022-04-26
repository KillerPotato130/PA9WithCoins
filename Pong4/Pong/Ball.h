//#pragma once
//
// 
// ARCHIVE STUFFF
// 
// 
// 
//// This example will use SFML libraries to implement
//// the game of Pong
//
//// History: 4/15 - Added basic (unfinished) movements to the paddles and game ball.
////                 Discussed different approaches to making movements. Worked
////                 with some basic collision detection between objects as well.
////          4/13 - Created classes for Paddle and Ball. Learned to position, size
////                and color the paddle and ball objects. These objects
////                were drawn on the window.
////          4/8 - Started from the SFML tutorial code that draws
////                a circle in the window. Discussed the general
////                setup of games in SFML. Started working on a Paddle
////                class.
//
//#include <SFML/Audio.hpp>
//#include <SFML/Graphics.hpp>
//#include <chrono>
//
//
//class Animation {
//public:
//    Animation() = default;
//    Animation(int x, int y, int width, int height) {
//        texture.loadFromFile("professor_walk_cycle_no_hat.png");
//        for (int i = 0; i < nFrames; i++) {
//            frames[i] = { x + i * width, y,width, height };
//        }
//    }
//
//
//
//    void ApplyToSprite(sf::Sprite& s) const {
//        s.setTexture(texture);
//        s.setTextureRect(frames[iFrame]);
//    }
//
//    void update(float dt) {
//        time += dt;
//        while (time >= holdTime) {
//            time -= holdTime;
//            Advance();
//        }
//    }
//private:
//    void Advance() {
//        if (++iFrame >= nFrames) {
//            iFrame = 0;
//        }
//    }
//private:
//    static constexpr int nFrames = 8;
//    static constexpr float holdTime = 0.1;
//    sf::Texture texture;
//    sf::IntRect frames[nFrames];
//    int iFrame = 0;
//    float time = 0.0;
//
//
//};
//
//
//class Character {
//private:
//    enum class AnimationIndex {
//        WalkingUp,
//        WalkingDown,
//        WalkingLeft,
//        WalkingRight,
//        Count
//    };
//public:
//    Character(const sf::Vector2f& newPos)
//    {
//        pos = newPos;
//        sprite.setTextureRect({ 0,0,64,64 });
//        animations[int(AnimationIndex::WalkingUp)] = Animation(64, 0, 64, 64);
//        animations[int(AnimationIndex::WalkingDown)] = Animation(64, 128, 64, 64);
//        animations[int(AnimationIndex::WalkingLeft)] = Animation(64, 64, 64, 64);
//        animations[int(AnimationIndex::WalkingRight)] = Animation(64, 192, 64, 64);
//    }
//
//    void setPos(const sf::Vector2f& newPos) {
//        pos = newPos;
//    }
//
//    void draw(sf::RenderTarget& rt) const {
//
//        rt.draw(sprite);
//    }
//
//    void setDirection(const sf::Vector2f& dir) {
//
//        vel = dir * speed;
//        if (dir.x > 0.0) {
//            curAnimation = AnimationIndex::WalkingRight;
//        }
//        else if (dir.x < 0.0) {
//            curAnimation = AnimationIndex::WalkingLeft;
//        }
//        else if (dir.y < 0.0) {
//            curAnimation = AnimationIndex::WalkingUp;
//        }
//        else if (dir.y > 0.0) {
//            curAnimation = AnimationIndex::WalkingDown;
//        }
//    }
//
//    void update(float dt) {
//        // sf::Vector2f prevPos = pos;  
//         //pos += vel * dt;
//
//
//
//        animations[int(curAnimation)].update(dt);
//        animations[int(curAnimation)].ApplyToSprite(sprite);
//
//        sprite.setPosition(pos);
//    }
//private:
//    static constexpr float speed = 100.0;
//    sf::Vector2f pos;
//    sf::Vector2f vel = { 0.0, 0.0 };
//    sf::Sprite sprite;
//    Animation animations[int(AnimationIndex::Count)];
//    AnimationIndex curAnimation = AnimationIndex::WalkingDown;
//};
//
//
//
//
//
//
//int main()
//{
//    int half_Sprite_x = 0, hald_sprite_y = 0;
//    bool keyPress = false;
//    // Create the main window
//    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML window");
//
//    //create sprite
//
//    Character model({ float(window.getSize().x) / 2 - 32 ,float(window.getSize().y) / 2 - 32 });
//
//    //timepoint for delta time measurement
//    auto tp = std::chrono::steady_clock::now();
//
//
//    // Start the game loop
//    while (window.isOpen())
//    {
//        // Process events
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            // Close window: exit
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        // get dt
//        float dt;
//        {
//            const auto new_tp = std::chrono::steady_clock::now();
//            dt = std::chrono::duration<float>(new_tp - tp).count();
//            tp = new_tp;
//        }
//
//        //handle input
//        sf::Vector2f dir = { 0.0, 0.0 };
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
//            dir.y -= 1.0;
//            keyPress = true;
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
//            dir.y += 1.0;
//            keyPress = true;
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
//            dir.x -= 1.0;
//            keyPress = true;
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
//            dir.x += 1.0;
//            keyPress = true;
//        }
//
//        if (keyPress == true) {
//            model.setDirection(dir);
//
//
//
//            //update model
//            model.update(dt);
//
//            keyPress = false;
//        }
//
//
//
//
//        // Clear screen
//        window.clear();
//        // Draw the sprite
//        model.draw(window);
//
//        // Update the window
//        window.display();
//    }
//    return EXIT_SUCCESS;
//}
