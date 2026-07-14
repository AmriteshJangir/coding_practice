class LFUCache{
    int capacity,minFreq;
    unordered_map<int,int> keyToVal,keyToFreq;
    unordered_map<int,list<int>> freqToKeys;
    unordered_map<int,list<int>::iterator> keyToIter;

    void updateFreq(int key){
        int freq=keyToFreq[key];
        freqToKeys[freq].erase(keyToIter[key]);
        if(freqToKeys[freq].empty()){
            freqToKeys.erase(freq);
            if(minFreq==freq) minFreq++;
        }
        keyToFreq[key]++;
        freqToKeys[freq+1].push_back(key);
        keyToIter[key]=--freqToKeys[freq+1].end();
    }

public:
    LFUCache(int capacity){
        this->capacity=capacity;
        minFreq=0;
    }

    int get(int key){
        if(capacity==0||!keyToVal.count(key)) return -1;
        updateFreq(key);
        return keyToVal[key];
    }

    void put(int key,int value){
        if(capacity==0) return;
        if(keyToVal.count(key)){
            keyToVal[key]=value;
            updateFreq(key);
            return;
        }
        if((int)keyToVal.size()==capacity){
            int rem=freqToKeys[minFreq].front();
            freqToKeys[minFreq].pop_front();
            if(freqToKeys[minFreq].empty()) freqToKeys.erase(minFreq);
            keyToVal.erase(rem);
            keyToFreq.erase(rem);
            keyToIter.erase(rem);
        }
        keyToVal[key]=value;
        keyToFreq[key]=1;
        freqToKeys[1].push_back(key);
        keyToIter[key]=--freqToKeys[1].end();
        minFreq=1;
    }
};