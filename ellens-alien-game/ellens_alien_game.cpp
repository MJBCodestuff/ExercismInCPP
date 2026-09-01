namespace targets {


    class Alien
    {
    private:
        int health {};
    public:

        int x_coordinate {};
        int y_coordinate {};

        Alien(int x_coordinate, int y_coordinate)
        {
            this->health = 3;
            this->x_coordinate = x_coordinate;
            this->y_coordinate = y_coordinate;
        }

        int get_health()
        {
            return this->health;
        }

        bool hit()
        {
            if (health > 0)
                --health;
            return true;
        }

        bool is_alive()
        {
            return health > 0;
        }

        bool teleport(int new_x, int new_y)
        {
            x_coordinate = new_x;
            y_coordinate = new_y;

            return true;
        }

        bool collision_detection(Alien comparison_target)
        {
            return (x_coordinate == comparison_target.x_coordinate
                 && y_coordinate == comparison_target.y_coordinate);

        }


    };
}  // namespace targets
