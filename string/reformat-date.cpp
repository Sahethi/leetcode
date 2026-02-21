class Solution {
public:
    string reformatDate(string date) {

        stringstream ss(date);
        vector<string> date1;
        string d;
        while (ss >> d) {
            date1.push_back(d);
        }

        string day = date1[0];
        string month = date1[1];
        string year = date1[2];

        unordered_map<string, string> months = {
            {"Jan", "01"}, {"Feb", "02"},
            {"Mar", "03"}, {"Apr", "04"},
            {"May", "05"}, {"Jun", "06"},
            {"Jul", "07"}, {"Aug", "08"},
            {"Sep", "09"}, {"Oct", "10"},
            {"Nov", "11"}, {"Dec", "12"}
        };

        string dateOnly = "";
        for(int i=0; i<day.size(); i++){
            if(day[i] >= '0' && day[i] <= '9'){
                dateOnly += day[i];
            }
        }

        if(dateOnly.size() == 1){
            dateOnly = '0' + dateOnly;
        }

        return year + "-" + months[month] + "-" + dateOnly;
    }
};