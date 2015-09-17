#include <iostream>

const int MAX_INT = 32767;

void wavefront_step(int** &map, int pos_r, int pos_c, int &next_r, int &next_c);

int main(int argc, char* argv[])
{
    int i, j;
    int next_c, next_r;
    int** map;
    
    map = new(std::nothrow) int*[3];
    
    for(i = 1; i <= 3; ++i)
    {
        map[i - 1] = new(std::nothrow) int[3];
        for(j = 0; j < 3; ++j)
        {
            map[i - 1][j] = j + i;
        }
    }
    map[1][2] = 0;
    
   
    wavefront_step(map, 1, 1, next_r, next_c);
    std::cout << next_r << ", " << next_c << std::endl;
    return 0;
}

void wavefront_step(int** &map, int pos_r, int pos_c, int &next_r, int &next_c)
{
    int i, cost, lowest_cost, lowest_c, lowest_r;
    
    lowest_cost = MAX_INT;
    
    for(i = 0; i < 8; ++i)
    {
        switch(i)
        {
            case 0:
                cost = map[pos_r - 1][pos_c];
                lowest_c = pos_c;
                lowest_r = pos_r - 1;
                break;
            case 1:
                cost = map[pos_r - 1][pos_c + 1];
                lowest_c = pos_c + 1;
                lowest_r = pos_r - 1;
                break;
            case 2:
                cost = map[pos_r][pos_c + 1];
                lowest_c = pos_c + 1;
                lowest_r = pos_r;
                break;
            case 3:
                cost = map[pos_r + 1][pos_c + 1];
                lowest_c = pos_c + 1;
                lowest_r = pos_r + 1;
                break;
            case 4:
                cost = map[pos_r + 1][pos_c];
                lowest_c = pos_c;
                lowest_r = pos_r + 1;
                break;
            case 5:
                cost = map[pos_r + 1][pos_c - 1];
                lowest_c = pos_c - 1;
                lowest_r = pos_r + 1;
                break;
            case 6:
                cost = map[pos_r][pos_c - 1];
                lowest_c = pos_c - 1;
                lowest_r = pos_r;
                break;
            case 7:
                cost = map[pos_r -1][pos_c -1];
                lowest_c = pos_c - 1;
                lowest_r = pos_r - 1;
                break;
            default:
                break;
        }
        //check to see if the current cost is lower than the lowest cost
        if(cost > 0 && cost < lowest_cost)
        {
            //set current cost to lowest cost
            lowest_cost = cost;
            //save the position of the lowest cost node
            next_c = lowest_c;
            next_r = lowest_r;
        }
    }
}