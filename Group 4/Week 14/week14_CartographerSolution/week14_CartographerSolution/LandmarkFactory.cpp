#include "LandmarkFactory.h"

std::unique_ptr<Landmark> LandmarkFactory::create(
        const std::string& type, 
        const std::string& name, 
        Coordinates coordinates, 
        const int thread, 
        const std::string extra
)
{
    
    if (type == "settlement")
    {
        return std::make_unique<Settlement>
            (type, name, coordinates.x, coordinates.y, thread, std::stoi(extra));
    }
    if (type == "dungeon")
    {
        return std::make_unique<Dungeon>
            (type, name, coordinates.x, coordinates.y, thread, std::stoi(extra));
    }
    if (type == "ruin")
    {
        return std::make_unique<Ruin>
            (type, name, coordinates.x, coordinates.y, thread, extra);
    }
    if (type == "natural")
    {
        return std::make_unique<NaturalFeature>
            (type, name, coordinates.x, coordinates.y, thread, NaturalFeature::stringToKind(extra));
    }

    throw std::invalid_argument("A landmark of such type doesn't exist");
}
