#include "texture.h"

void Texture::Release() {
  if (m_pTextureView) {
    m_pTextureView->Release();
    m_pTextureView = nullptr;
  }
}

Texture::Texture(ID3D11Device* device, ID3D11DeviceContext* deviceContext, const wchar_t* filename) {
    m_pTextureView = nullptr;

    HRESULT hr = S_OK;
    hr = DirectX::CreateDDSTextureFromFile(device, filename, nullptr, &m_pTextureView);
}

