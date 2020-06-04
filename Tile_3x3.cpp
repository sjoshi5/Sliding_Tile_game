// 3X3 Sliding Tile Game
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

//Class Game
class game {
public :
    //Function to play game
    void play()
    {
        bool p = true;
         string a;
        while( p )
        {
            createBoard();
            while( !winC() )
            {
             drawBoard();
             getMove();
            }
            drawBoard();
             cout << "\n\nCongratulations!\nPlay again (Y/N)?";
             cin >> a; if( a != "Y" && a != "y" ) break;
        }
    }
private:
    //Create the board
    void createBoard()
    {
        int i;
        vector<int> v;
        for( i=1; i < 9; i++ )
        { brd[i - 1] = i;
        }
        brd[8] = 0;
        x = y = 2;
        for( i = 0; i < 1000; i++ )
        {
            possibleMvts( v );
            move( v[rand() % v.size()] );
            v.clear();
        }
    }
    
    //Move the tile
    void move( int d )
    {
        int t = x + y * 3;
        switch( d )
        {
            case 1: y--; break;
            case 2: x++; break;
            case 4: y++; break;
            case 8: x--;
        }
        brd[t] = brd[x + y * 3];
        brd[x + y * 3] = 0;
    }
    
    //Possible movements according to position of blank tile
    void possibleMvts(  vector<int>& v )
    {
        if( x < 2 )
            v.push_back( 2 );
        if( x > 0 )
            v.push_back( 8 );
        if( y < 2 )
            v.push_back( 4 );
        if( y > 0 )
            v.push_back( 1 );
    }
    
    //Display the board after movements
    void drawBoard()
    {
        int r;
        cout << "\n\n";
        for( int y = 0; y < 3; y++ )
        {
            cout << "________________\n";
            for( int x = 0; x < 3; x++ )
            {
                r = brd[x + y * 3];
                cout << "| ";
                if( r < 10 )
                    cout << " ";
                if( !r )
                    cout << "  ";
                else
                    cout << r << " ";
            }
             cout << "|\n";
        }
        cout << "________________\n";
    }
    
    //Input the move
    void getMove()
    {
        vector<int> v;
        possibleMvts( v );
        vector<int> p;
        getTiles( p, v ); unsigned int i;
        while( true )
        {
            cout << "\nPossible moves: ";
            for(i = 0; i < p.size(); i++)
            {cout << p[i] << " ";}
            int z;
            cout<<"\n Your response: ";
            cin >> z;
            cout<<endl;
            for( i = 0; i < p.size(); i++ )
            {
                if( z == p[i] )
                {   move(v[i]);
                    return;
                }
            }
        }
    }
    
    //Get the tiles corresponding to possible movements
    void getTiles(vector<int>& p, vector<int>& v)
    {
        for( unsigned int t = 0; t < v.size(); t++ )
        {
            int xx = x, yy = y;
            switch( v[t] )
            {
                case 1: yy--; break;
                case 2: xx++; break;
                case 4: yy++; break;
                case 8: xx--;
            }
            p.push_back( brd[xx + yy * 3] );
        }
    }
    
    //Winning Condition
    bool winC()
    {
        for( int i = 1; i < 9; i++ )
        {
            if( brd[i-1] != i )
                return false;
        }
        return true;
    }
    int brd[9], x, y;
};

//Main function
int main( )
{
    game p;
    p.play();
    return 0;
}
