class UndergroundSystem {
public:
     unordered_multimap<int, pair<pair<string,string>, int>> m;
    UndergroundSystem() {
       
    }
    
    void checkIn(int id, string stationName, int t) {
        pair<string,string> p({stationName,"nill"});
        pair<pair<string,string>, int> mp({p,t});
        m.insert(make_pair(id, mp));
    }
    
    void checkOut(int id, string stationName, int t) {
        auto it=m.find(id);
        while(it!=m.end() && it->first==id){
           pair<pair<string,string>, int> &mp =it->second;
            pair<string,string> &p=mp.first;
            if(p.second=="nill")
            {
                p.second=stationName;
                mp.second=t-mp.second;
                break;
            }
            it++;
            } 
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto it =m.begin();
        pair<string,string> p({startStation, endStation});
        long sum=0;
        int tot=0;
         while(it!=m.end())
         {
             pair<pair<string,string>, int> &mp =it->second;
             if(mp.first==p)
             {
                 tot++;
                 sum+=mp.second;
             }
             it++;
         }
        return (sum*1.0)/tot;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */