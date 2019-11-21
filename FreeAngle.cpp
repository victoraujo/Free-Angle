#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

int main (){
    int x,y,xm,ym,xm2,ym2,d,a,e,f=0,g=0,h,i,b=0,t=1,aux;
    float dist,m,ang,d1,d2,dist2,kt,d3,d4,d5;
    int adv[4][2];
    int pontos[12][2];
    int bolax,bolay,jogx,jogy;

    sf::RenderWindow window(sf::VideoMode(930, 630), "Path Planning");
    sf::RectangleShape rectangle(sf::Vector2f(930, 630));
    rectangle.setFillColor(sf::Color(50, 200, 50));
    sf::VertexArray lines(sf::LinesStrip, 13);
    lines[0].position = sf::Vector2f(15, 15);
    lines[1].position = sf::Vector2f(15, 615);
    lines[2].position = sf::Vector2f(915, 615);
    lines[3].position = sf::Vector2f(915, 215);
    lines[4].position = sf::Vector2f(815, 215);
    lines[5].position = sf::Vector2f(815, 415);
    lines[6].position = sf::Vector2f(915, 415);
    lines[7].position = sf::Vector2f(915, 15);
    lines[8].position = sf::Vector2f(15, 15);
    lines[9].position = sf::Vector2f(15, 215);
    lines[10].position = sf::Vector2f(115, 215);
    lines[11].position = sf::Vector2f(115, 415);
    lines[12].position = sf::Vector2f(15, 415);
    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(465, 15)),
        sf::Vertex(sf::Vector2f(465, 615))};
    sf::CircleShape circle(5);
    circle.setFillColor(sf::Color::White);
    circle.setPosition(460,310);
    sf::CircleShape bola(5);
    bola.setFillColor(sf::Color(255,165,0));
    bola.setPosition(460,310);
    sf::CircleShape circle2(15);
    circle2.setFillColor(sf::Color::Red);
    circle2.setPosition(550,300);
    circle2.setOutlineColor(sf::Color::Black);
    circle2.setOutlineThickness(3);
    sf::CircleShape circle3(15);
    circle3.setFillColor(sf::Color::Blue);
    circle3.setPosition(345,300);
    circle3.setOutlineColor(sf::Color::Black);
    circle3.setOutlineThickness(3);
    sf::CircleShape circle4(15);
    circle4.setFillColor(sf::Color::Blue);
    circle4.setPosition(300,300);
    circle4.setOutlineColor(sf::Color::Black);
    circle4.setOutlineThickness(3);
    sf::CircleShape circle5(15);
    circle5.setFillColor(sf::Color::Blue);
    circle5.setPosition(255,300);
    circle5.setOutlineColor(sf::Color::Black);
    circle5.setOutlineThickness(3);
    sf::CircleShape circle6(15);
    circle6.setFillColor(sf::Color::Blue);
    circle6.setPosition(210,300);
    circle6.setOutlineColor(sf::Color::Black);
    circle6.setOutlineThickness(3);
    sf::CircleShape circle7(15);
    circle7.setFillColor(sf::Color::Blue);
    circle7.setPosition(110,300);
    circle7.setOutlineColor(sf::Color::Black);
    circle7.setOutlineThickness(3);

    while(window.isOpen()){
        bolax= bola.getPosition().x + 5;
        bolay= bola.getPosition().y + 5;
        jogx= circle2.getPosition().x + 15;
        jogy= circle2.getPosition().y + 15;
        adv[0][0]=circle3.getPosition().x + 15;
        adv[0][1]=circle3.getPosition().y + 15;
        adv[1][0]=circle4.getPosition().x + 15;
        adv[1][1]=circle4.getPosition().y + 15;
        adv[2][0]=circle5.getPosition().x + 15;
        adv[2][1]=circle5.getPosition().y + 15;
        adv[3][0]=circle6.getPosition().x + 15;
        adv[3][1]=circle6.getPosition().y + 15;
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
			  }
        if(event.type == sf::Event::MouseButtonPressed){

            if((x>=bolax - 5  && x<= bolax + 5)&&(y>=bolay - 5 && y<=bolay + 5)){d=1;}
            if((x>=jogx -15  && x<=jogx + 15)&&(y>=jogy - 15 && y<=jogy + 15)){e=1;}
            if((x>=adv[0][0] - 15  && x<=adv[0][0] + 15)&&(y>=adv[0][1] - 15 && y<=adv[0][1] + 15)){f=1;}
            if((x>=adv[1][0] - 15  && x<=adv[1][0] + 15)&&(y>=adv[1][1] - 15 && y<=adv[1][1] + 15)){g=1;}
            if((x>=adv[2][0] - 15  && x<=adv[2][0] + 15)&&(y>=adv[2][1] - 15 && y<=adv[2][1] + 15)){h=1;}
            if((x>=adv[3][0] - 15  && x<=adv[3][0] + 15)&&(y>=adv[3][1] - 15 && y<=adv[3][1] + 15)){b=1;}
            }
        if(event.type == sf::Event::MouseButtonReleased){
            d=2;e=2;f=2;g=2;h=2;b=2;i=2;}
        if (event.type == sf::Event::MouseMoved)
            {
            x=event.mouseMove.x;
            y=event.mouseMove.y;
            }
        if(d==1){bola.setPosition(x-5,y-5);}
        if(e==1){circle2.setPosition(x-15,y-15);}
        if(f==1){circle3.setPosition(x-15,y-15);}
        if(g==1){circle4.setPosition(x-15,y-15);}
        if(h==1){circle5.setPosition(x-15,y-15);}
        if(b==1){circle6.setPosition(x-15,y-15);}
        window.clear();
        window.draw(rectangle);
        window.draw(line, 5, sf::Lines);
        window.draw(circle);
        window.draw(lines);
        window.draw(circle3);
        window.draw(circle4);
        window.draw(circle5);
        window.draw(circle2);
        window.draw(circle6);
        window.display();




        }
        
        
        
        }










}