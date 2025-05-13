#pragma once


class PolygonVector : public Circle {
public:
	//	void DrawPolygon(HDC hdc);
	void DrawPolygon(HDC hdc, vector<Vector2>& vertexs);
	void DrawPolygonAbs(HDC hdc, vector<Vector2>& vertexs, Vector2& pos);

	bool IsLineCircleCollision(const Vector2& P1, const Vector2& P2);
	bool IsPolygonCircleCollision(PolygonVector* polygon);

	vector<Vector2> SumCenterVertexs(const vector<Vector2>& vertexs);

	void DrawRotatedRectangle(HDC hdc, vector<Vector2> vertex, float angle);

	void DrawRotatedRectangleAbs(HDC hdc, vector<Vector2> vertex, float angle, Vector2 pos);


	vector<Vector2> GetVertexs() { return vertexs; }
	void AddVertexs(Vector2 vert) { vertexs.push_back(vert); }

protected:
	vector<Vector2> vertexs;


};