static float cross(const ImVec2& O, const ImVec2& A, const ImVec2& B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
