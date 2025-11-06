for (auto face : player.faces) {
    dl->AddConvexPolyFilled(face.data(), face.size(), c);
    dl->AddPolyline(face.data(), face.size(), ImColor(c.Value.x,c.Value.y,c.Value.z,255.f), true, 2);
}
