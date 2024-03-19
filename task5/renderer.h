#pragma once

#include <d3d11.h>
#include <dxgi.h>
#include <d3d11.h>
#include <directxmath.h>
#include <string>

#include "camera.h"
#include "input.h"
#include "utils.h"
#include "cubeMap.h"
#include "texture.h"

struct Vertex {
  float x, y, z;
  float u, v;
};


struct AuxRect {
    XMFLOAT3 v[4];
};


struct WorldMatrixBuffer {
  XMMATRIX mWorldMatrix;
};

struct SceneMatrixBuffer {
  XMMATRIX mViewProjectionMatrix;
};

struct TransparentWorldBuffer
{
  DirectX::XMMATRIX worldMatrix;
  DirectX::XMFLOAT4 color;
};

struct VertexPos
{
  float x, y, z;
};

class Renderer {
private:
  ID3D11Device* m_pDevice = nullptr;
  ID3D11DeviceContext* m_pDeviceContext = nullptr;
  IDXGISwapChain* m_pSwapChain = nullptr;
  ID3D11RenderTargetView* m_pBackBufferRTV = nullptr;

  ID3D11Buffer* m_pIndexBuffer = nullptr;
  ID3D11Buffer* m_pVertexBuffer = nullptr;

  ID3D11VertexShader* m_pVertexShader = nullptr;
  ID3D11PixelShader* m_pPixelShader = nullptr;

  ID3D11InputLayout* m_pInputLayout = nullptr;

  ID3D11Buffer* m_pWorldMatrixBuffer = nullptr;
  ID3D11Buffer* m_pWorldMatrixBuffer1 = nullptr;

  ID3D11Buffer* m_pSceneMatrixBuffer = nullptr;
  ID3D11RasterizerState* m_pRasterizerState = nullptr;
  ID3D11SamplerState* m_pSampler = nullptr;
  
  ID3D11DepthStencilState* m_pDepthState = nullptr;

  ID3D11VertexShader* m_pTransparentVertexShader = nullptr;
  ID3D11PixelShader* m_pTransparentPixelShader = nullptr;
  ID3D11InputLayout* m_pTransparentInputLayout = nullptr;
  ID3D11Buffer* m_pTransparentVertexBuffer = nullptr;
  ID3D11Buffer* m_pTransparentIndexBuffer = nullptr;
  ID3D11Buffer* m_pTransparentWorldBuffer = nullptr;
  ID3D11Buffer* m_pTransparentWorldBuffer1 = nullptr;
  ID3D11Buffer* m_pTransparentSceneBuffer = nullptr;
  ID3D11RasterizerState* m_pTransparentRasterizerState = nullptr;
  ID3D11DepthStencilState* m_pTransparentDepthState = nullptr;
  ID3D11BlendState* m_pTransparentBlendState = nullptr;

  ID3D11Texture2D* m_pDepthBuffer = nullptr;
  ID3D11DepthStencilView* m_pDepthBufferDSV = nullptr;

  UINT m_width = 1280;
  UINT m_height = 720;

  Camera* m_pCamera = nullptr;
  Input* m_pInput = nullptr;

  CubeMap* m_pCubeMap = nullptr;
  std::vector<Texture> m_textureArray;

  float m_forwardSpeed = 0.0f;
  float m_backwardSpeed = 0.0f;
  float m_leftSpeed = 0.0f;
  float m_rightSpeed = 0.0f;
  float m_frameMove = 0.001f;
  XMFLOAT3 m_cubePos = XMFLOAT3(0.0f, 0.0f, 0.0f);
  AuxRect aux_rects[2];

  HRESULT setupBackBuffer();
  HRESULT initScene();
  void inputMovement();
  void MoveForward(bool keydown);
  void MoveBackward(bool keydown);
  void MoveLeft(bool keydown);
  void MoveRight(bool keydown);

public:
  bool deviceInit(HINSTANCE hinst, HWND hWnd, Camera* pCamera, Input* pInput);
  bool getState();
  bool render();
  void deviceCleanup();
  bool winResize(UINT width, UINT height);
};



