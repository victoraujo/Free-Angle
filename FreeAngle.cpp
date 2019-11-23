#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;


float distancia(int x1, int y1, int x2, int y2){                //calc dist entre 2 pontos
    float p;
    p = sqrt(pow(float(x1-x2), 2)+pow(float(y1-y2),2));
    return p;
}
int main (){
    int x,y,xm,ym,xm2,ym2,d,a,e,f=0,g=0,h,i,b=0,t=1,j=0,q=0,w=0,r=0,o=0,aux;
    float dist,m,ang,d1,d2,dist2,kt,d3,d4,d5;
    float ponto[9][4];
    int adv[9][2];
    int bolax,bolay,jogx,jogy,batata,cLateral2y,cLateral2x,cLateraly,cLateralx;

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
    circle2.setFillColor(sf::Color::Black);
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
    sf::CircleShape circle8(15);
    circle8.setFillColor(sf::Color::Blue);
    circle8.setPosition(345,400);
    circle8.setOutlineColor(sf::Color::Black);
    circle8.setOutlineThickness(3);
    sf::CircleShape circle9(15);
    circle9.setFillColor(sf::Color::Blue);
    circle9.setPosition(300,400);
    circle9.setOutlineColor(sf::Color::Black);
    circle9.setOutlineThickness(3);
    sf::CircleShape circle10(15);
    circle10.setFillColor(sf::Color::Blue);
    circle10.setPosition(255,400);
    circle10.setOutlineColor(sf::Color::Black);
    circle10.setOutlineThickness(3);
    sf::CircleShape circle11(15);
    circle11.setFillColor(sf::Color::Blue);
    circle11.setPosition(210,400);
    circle11.setOutlineColor(sf::Color::Black);
    circle11.setOutlineThickness(3);
    sf::CircleShape circle12(15);
    circle12.setFillColor(sf::Color::Blue);
    circle12.setPosition(110,400);
    circle12.setOutlineColor(sf::Color::Black);
    circle12.setOutlineThickness(3);
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
        adv[4][0]=circle7.getPosition().x + 15;
        adv[4][1]=circle7.getPosition().y + 15;
        adv[5][0]=circle8.getPosition().x + 15;
        adv[5][1]=circle8.getPosition().y + 15;
        adv[6][0]=circle9.getPosition().x + 15;
        adv[6][1]=circle9.getPosition().y + 15;
        adv[7][0]=circle10.getPosition().x + 15;
        adv[7][1]=circle10.getPosition().y + 15;
        adv[8][0]=circle11.getPosition().x + 15;
        adv[8][1]=circle11.getPosition().y + 15;

        
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
            if(event.type == sf::Event::MouseButtonPressed){

                if((x>=bolax - 5  && x<= bolax + 5)&&(y>=bolay - 5 && y<=bolay + 5))
                    d=1;
                if((x>=jogx -15  && x<=jogx + 15)&&(y>=jogy - 15 && y<=jogy + 15))
                    e=1;
                if((x>=adv[0][0] - 15  && x<=adv[0][0] + 15)&&(y>=adv[0][1] - 15 && y<=adv[0][1] + 15))
                    f=1;
                if((x>=adv[1][0] - 15  && x<=adv[1][0] + 15)&&(y>=adv[1][1] - 15 && y<=adv[1][1] + 15))
                    g=1;
                if((x>=adv[2][0] - 15  && x<=adv[2][0] + 15)&&(y>=adv[2][1] - 15 && y<=adv[2][1] + 15))
                    h=1;
                if((x>=adv[3][0] - 15  && x<=adv[3][0] + 15)&&(y>=adv[3][1] - 15 && y<=adv[3][1] + 15))
                    b=1;

                if((x>=adv[4][0] - 15  && x<=adv[4][0] + 15)&&(y>=adv[4][1] - 15 && y<=adv[4][1] + 15))
                    j=1;
                if((x>=adv[5][0] - 15  && x<=adv[5][0] + 15)&&(y>=adv[5][1] - 15 && y<=adv[5][1] + 15))
                    q=1;
                if((x>=adv[6][0] - 15  && x<=adv[6][0] + 15)&&(y>=adv[6][1] - 15 && y<=adv[6][1] + 15))
                    w=1;
                if((x>=adv[7][0] - 15  && x<=adv[7][0] + 15)&&(y>=adv[7][1] - 15 && y<=adv[7][1] + 15))
                    r=1;
                if((x>=adv[8][0] - 15  && x<=adv[8][0] + 15)&&(y>=adv[8][1] - 15 && y<=adv[8][1] + 15))
                    o=1;
               
            }
            if(event.type == sf::Event::MouseButtonReleased){
                d=2;
                e=2;
                f=2;
                g=2;
                h=2;
                b=2;
                j=2;
                q=2;
                w=2;
                r=2;
                o=2;
            

            }
            if (event.type == sf::Event::MouseMoved)
            {
                x=event.mouseMove.x;
                y=event.mouseMove.y;
            }
        }
        if(d==1)
            bola.setPosition(x-5,y-5);
        if(e==1)
            circle2.setPosition(x-15,y-15);
        if(f==1)
            circle3.setPosition(x-15,y-15);
        if(g==1)
            circle4.setPosition(x-15,y-15);
        if(h==1)
            circle5.setPosition(x-15,y-15);
        if(b==1)
            circle6.setPosition(x-15,y-15);
        if(j==1)
            circle7.setPosition(x-15,y-15);
        if(q==1)
            circle8.setPosition(x-15,y-15);
        if(w==1)
            circle9.setPosition(x-15,y-15);
        if(r==1)
            circle10.setPosition(x-15,y-15);
        if(o==1)
            circle11.setPosition(x-15,y-15);

        //FREE ANGLE
        for(i=0;i<9;i++){
            dist = distancia(adv[i][0],adv[i][1], jogx, jogy);
            float dist2 = sqrt(pow(dist, 2) + pow(18, 2));

            if(adv[i][0]-jogx!=0)
                m = float(adv[i][1]-jogy)/float(adv[i][0]-jogx);

            
            float alfa = asin(18/dist);
            float beta = atan(m);

            if(adv[i][0]-jogx==0){
                if (adv[i][1] > jogy) beta = 1.5708;                       //Adv em cima
                else beta = -1.5708;
            }

            if(jogx > adv[i][0])
                batata=-1;

            else
                batata=1;

            ponto[i][0] = jogx + int(batata*dist2*cos(beta+alfa));
            ponto[i][1] = jogy + int(batata*dist2*sin(beta+alfa));

            ponto[i][2] = jogx + int(batata*dist2*cos(beta-alfa));
            ponto[i][3] = jogy + int(batata*dist2*sin(beta-alfa));

            
        }


        window.clear();
        window.draw(rectangle);
        window.draw(line, 2, sf::Lines);
        window.draw(circle);
        window.draw(lines);

        for(i=0;i<9;i++){
            sf::VertexArray lateral(sf::Triangles, 3);
            lateral[0].position=sf::Vector2f(ponto[i][0], ponto[i][1]);
            lateral[1].position = sf::Vector2f(jogx, jogy);
            lateral[2].position=sf::Vector2f(ponto[i][2], ponto[i][3]);
            lateral[0].color = sf::Color::Red;
            lateral[1].color = sf::Color::Yellow;
            lateral[2].color = sf::Color::Blue;
            window.draw(lateral);
        }
        window.draw(circle3);
        window.draw(circle4);
        window.draw(circle5);
        window.draw(circle2);
        window.draw(circle6);
        window.draw(circle8);
        window.draw(circle9);
        window.draw(circle10);
        window.draw(circle11);
        window.draw(circle7);
        window.display();

        }
    }

