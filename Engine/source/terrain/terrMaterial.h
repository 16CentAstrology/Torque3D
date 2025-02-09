//-----------------------------------------------------------------------------
// Copyright (c) 2012 GarageGames, LLC
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//-----------------------------------------------------------------------------

#ifndef _TERRMATERIAL_H_
#define _TERRMATERIAL_H_

#ifndef _SIMBASE_H_
#include "console/simBase.h"
#endif

#include "T3D/assets/ImageAsset.h"

/// The TerrainMaterial class orginizes the material settings 
/// for a single terrain material layer.
class TerrainMaterial : public SimObject
{
   typedef SimObject Parent;

protected:

   ///
  //FileName mDiffuseMap;

   //AssetPtr<ImageAsset> mDiffuseAsset;

   DECLARE_IMAGEASSET(TerrainMaterial, DiffuseMap, onDiffuseMapChanged, GFXStaticTextureSRGBProfile);
   DECLARE_ASSET_SETGET(TerrainMaterial, DiffuseMap);

   /// The size of the diffuse base map in meters 
   /// used to generate its texture coordinates.
   F32 mDiffuseSize;

   ///
   DECLARE_IMAGEASSET(TerrainMaterial, NormalMap, onNormalMapChanged, GFXNormalMapProfile);
   DECLARE_ASSET_SETGET(TerrainMaterial, NormalMap);

   ///
   DECLARE_IMAGEASSET(TerrainMaterial, DetailMap, onDetailMapChanged, GFXStaticTextureProfile);
   DECLARE_ASSET_SETGET(TerrainMaterial, DetailMap);
   
   /// The size of the detail map in meters used
   /// to generate the texture coordinates for the
   /// detail and normal maps.
   F32 mDetailSize;

   /// 
   F32 mDetailStrength;

   /// 
   F32 mDetailDistance;

   ///
   DECLARE_IMAGEASSET(TerrainMaterial, ORMConfigMap, onORMConfigMapChanged, GFXStaticTextureProfile);
   DECLARE_ASSET_SETGET(TerrainMaterial, ORMConfigMap);

   bool mIsSRGB;
   bool mInvertRoughness;

   /// Normally the detail is projected on to the xy 
   /// coordinates of the terrain.  If this flag is true
   /// then this detail is projected along the xz and yz
   /// planes.
   bool mSideProjection;

   DECLARE_IMAGEASSET(TerrainMaterial, MacroMap, onMacroMapChanged, GFXStaticTextureProfile);
   DECLARE_ASSET_SETGET(TerrainMaterial, MacroMap);
   F32 mMacroSize;
   F32 mMacroStrength;
   F32 mMacroDistance;

   ///
   F32 mParallaxScale;

   /// Depth for blending the textures using the new
   /// blending method. Higher numbers = larger blend
   /// radius.
   F32 mBlendDepth;

   F32 mBlendContrast;

   F32 mBlendHardness;

public:

   TerrainMaterial();
   virtual ~TerrainMaterial();

   bool onAdd();
   static void initPersistFields();

   DECLARE_CONOBJECT( TerrainMaterial );

   /// This method locates the TerrainMaterial if it exists, tries 
   /// to create a new one if a valid texture path was passed, or
   /// returns a debug material if all else fails.
   static TerrainMaterial* findOrCreate( const char *nameOrPath );

   /// Returns the default warning terrain material used when
   /// a material is not found or defined.
   static TerrainMaterial* getWarningMaterial();

   F32 getDiffuseSize() const { return mDiffuseSize; }

   F32 getDetailSize() const { return mDetailSize; }

   F32 getDetailStrength() const { return mDetailStrength; }

   F32 getDetailDistance() const { return mDetailDistance; }

   F32 getMacroSize() const { return mMacroSize; }

   F32 getMacroDistance() const { return mMacroDistance; }

   F32 getMacroStrength() const { return mMacroStrength; }

   bool useSideProjection() const { return mSideProjection; }

   F32 getParallaxScale() const { return mParallaxScale; }

   F32 getBlendDepth() const { return mBlendDepth; }

   F32 getBlendContrast() const { return mBlendContrast; }

   F32 getBlendHardness() const { return mBlendHardness; }

   bool getIsSRGB() const { return mIsSRGB; }

   bool getInvertRoughness() const { return mInvertRoughness; }

   void onDiffuseMapChanged() {}
   void onNormalMapChanged() {}
   void onDetailMapChanged() {}
   void onORMConfigMapChanged() {}
   void onMacroMapChanged() {}

};

#endif // _TERRMATERIAL_H_
