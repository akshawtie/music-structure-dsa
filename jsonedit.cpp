#include <iostream>
#include <fstream>
#include "json.hpp"
#include <string>

using json = nlohmann::json;
using namespace std;

class edit{
    public:
    void insert(string name,string artist)
    {
        json j;
        ifstream in("playlist.json");
        in>>j;
        in.close();
    
        j["playlist"].push_back({
            {"title",name},{"artist",artist}});

            ofstream out("playlist.json");
            out<<j.dump(2);
           out.close();

    }
    void insertstart(string name,string artist)
    {
        json j;
        ifstream in("playlist.json");
        in>>j;
        in.close();
        json song;
        song["title"]=name;
        song["artist"]=artist;
        j["playlist"].insert(j["playlist"].begin(), song);

            ofstream out("playlist.json");
            out<<j.dump(2);
           out.close();

    }};
int main()
{
    edit s;
    cout<<"Enter Song"<<endl;
    string song, artist;
    getline(cin,song);
    cout<<"Enter Artist"<<endl;
    getline(cin,artist);
    s.insertstart(song,artist);
    cout<<endl<<"Inserted At End";
    
}