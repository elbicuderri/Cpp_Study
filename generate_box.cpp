#include <iostream>
#include <algorithm>
#include <random>
#include <vector>

float Area(const std::vector<float>& box)
{
	float x1 = box[0];
	float y1 = box[1];
	float x2 = box[2];
	float y2 = box[3];

	float width = x2 - x1;
	float height = y2 - y1;

	float area = width * height;

	return area;
}

std::vector<float> generate_bbox(int height, int width) {
    unsigned int seed = std::rand();
    std::mt19937 gen_x1(seed);
    std::mt19937 gen_y1(seed+1);
    std::mt19937 gen_x2(seed+2);
    std::mt19937 gen_y2(seed+3);

    std::uniform_real_distribution<float> dis_x1(0.0f, static_cast<float>(height));
    std::uniform_real_distribution<float> dis_y1(0.0f, static_cast<float>(width));

    float x1 = dis_x1(gen_x1);
    float y1 = dis_y1(gen_y1);

    std::uniform_real_distribution<float> dis_x2(-1.0f * (static_cast<float>(height)), -x1);
    std::uniform_real_distribution<float> dis_y2(-1.0f * (static_cast<float>(width)), -y1);

    float x2 = -(dis_x2(gen_x2));
    float y2 = -(dis_y2(gen_y2));

    std::vector<float> box = {x1, y1, x2, y2};
    return box;
}

int main() {

    auto box1 = generate_bbox(10, 10);

    for (auto& e: box1) {
        std::cout << e << std::endl;
    }

    auto box1_size = Area(box1);

    std::cout << box1_size << std::endl;

    return 0;
}