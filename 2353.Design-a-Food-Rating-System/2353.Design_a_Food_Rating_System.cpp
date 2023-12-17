class FoodRatings {
public:
    unordered_map<string, int> food_rating;
    unordered_map<string, string> food_cuisine;
    unordered_map<string, set<pair<int, string>>> cuisine_food;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < foods.size(); i++){
            food_rating[foods[i]] = ratings[i];
            food_cuisine[foods[i]] = cuisines[i];
            cuisine_food[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        int prevRating = food_rating[food];
        food_rating[food] = newRating;
        string cuisine = food_cuisine[food];
        cuisine_food[cuisine].erase({-prevRating, food});
        cuisine_food[cuisine].insert({-newRating, food});        
    }
    
    string highestRated(string cuisine) {
        return cuisine_food[cuisine].begin()->second;
    }
};