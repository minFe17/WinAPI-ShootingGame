#pragma once


class PolygonVector : public Circle {
public:
	//	void DrawPolygon(HDC hdc);
	void DrawPolygon(HDC hdc, vector<Vector2>& vertexs);
	bool IsLineCircleCollision(const Vector2& P1, const Vector2& P2);
	bool IsPolygonCircleCollision(PolygonVector* polygon);

	vector<Vector2> SumCenterVertexs(const vector<Vector2>& vertexs);

	void DrawRotatedRectangle(HDC hdc, vector<Vector2> vertex, float angle);


	vector<Vector2> GetVertexs() { return vertexs; }
	void AddVertexs(Vector2 vert) { vertexs.push_back(vert); }

protected:
	vector<Vector2> vertexs;


};