uintptr_t prim = read<uintptr_t>(part.instance_ptr + offsets::Primitive);
CFrame cf = read<CFrame>(prim + offsets::CFrame);
vector3 size = read<vector3>(prim + offsets::PartSize);
static std::vector<std::vector<vector3>> faces = {
    {
        {-0.5f, 0.5f, -0.5f},
        {0.5f, 0.5f, -0.5f},
        {0.5f, -0.5f, -0.5f},
        {-0.5f, -0.5f, -0.5f}
    },
    {
        {-0.5f, 0.5f, 0.5f},
        {0.5f, 0.5f, 0.5f},
        {0.5f, -0.5f, 0.5f},
        {-0.5f, -0.5f, 0.5f}
    },
    {
        {-0.5f, 0.5f, 0.5f},
        {-0.5f, 0.5f, -0.5f},
        {-0.5f, -0.5f, -0.5f},
        {-0.5f, -0.5f, 0.5f},
    },
    {
        {0.5f, 0.5f, 0.5f},
        {0.5f, 0.5f, -0.5f},
        {0.5f, -0.5f, -0.5f},
        {0.5f, -0.5f, 0.5f},
    },
    {
        {0.5f, 0.5f, 0.5f},
        {0.5f, 0.5f, -0.5f},
        {-0.5f, 0.5f, -0.5f},
        {-0.5f, 0.5f, 0.5f},
    },
    {
        {0.5f, -0.5f, 0.5f},
        {0.5f, -0.5f, -0.5f},
        {-0.5f, -0.5f, -0.5f},
        {-0.5f, -0.5f, 0.5f},
    },
};
std::vector<ImVec2> points;
for (auto face : faces) {
    for (auto offset : face) {
        vector3 pos_offset = cf.translation + (cf * (size * offset)).translation;
        vector2 screen = world_to_screen(pos_offset, viewmatrix, dimensions);
        if (screen.x < 0 || screen.y < 0 || screen.x > dimensions.x || screen.y > dimensions.y) {
                break;
        }
        points.push_back(ImVec2(screen.x, screen.y));
    }
}
player_data.faces.push_back(convexHull(points));
