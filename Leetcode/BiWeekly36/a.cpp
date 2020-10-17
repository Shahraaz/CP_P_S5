class ParkingSystem
{
    vector<int> curr;

public:
    ParkingSystem(int big, int medium, int small)
    {
        curr = vector<int>(3);
        curr[0] = big;
        curr[1] = medium;
        curr[2] = small;
    }

    bool addCar(int carType)
    {
        carType--;
        if (curr[carType] > 0)
        {
            curr[carType]--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */