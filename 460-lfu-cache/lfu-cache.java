import java.util.*;

class LFUCache {

    private int capacity;
    private int minFreq;

    private Map<Integer, Integer> keyToVal;
    private Map<Integer, Integer> keyToFreq;
    private Map<Integer, LinkedHashSet<Integer>> freqToKeys;

    public LFUCache(int capacity) {
        this.capacity = capacity;
        this.minFreq = 0;
        keyToVal = new HashMap<>();
        keyToFreq = new HashMap<>();
        freqToKeys = new HashMap<>();
    }

    public int get(int key) {
        if (!keyToVal.containsKey(key))
            return -1;

        updateFrequency(key);
        return keyToVal.get(key);
    }

    public void put(int key, int value) {
        if (capacity == 0)
            return;

        if (keyToVal.containsKey(key)) {
            keyToVal.put(key, value);
            updateFrequency(key);
            return;
        }

        if (keyToVal.size() >= capacity) {
            // remove LFU key
            LinkedHashSet<Integer> keys = freqToKeys.get(minFreq);
            int evict = keys.iterator().next(); // LRU in this freq
            keys.remove(evict);
            keyToVal.remove(evict);
            keyToFreq.remove(evict);
        }

        keyToVal.put(key, value);
        keyToFreq.put(key, 1);
        freqToKeys.computeIfAbsent(1, k -> new LinkedHashSet<>()).add(key);
        minFreq = 1;
    }

    private void updateFrequency(int key) {
        int freq = keyToFreq.get(key);
        keyToFreq.put(key, freq + 1);

        freqToKeys.get(freq).remove(key);
        if (freqToKeys.get(freq).isEmpty()) {
            freqToKeys.remove(freq);
            if (freq == minFreq)
                minFreq++;
        }

        freqToKeys.computeIfAbsent(freq + 1, k -> new LinkedHashSet<>()).add(key);
    }
}
