#include <map>

#include "logger.h"
#include "navi2pg.h"

namespace
{
    using namespace NAVI2PG;

    Navi2PGConfig configurate(OGRDataSource* srcDataSource)
    {
        Navi2PGConfig configuration;

        NaviLayerConfuguration layerConf;
        FieldForCopy fieldForCopy;

        layerConf.hasSignature = false;

        layerConf.layerName = "beacon";
        layerConf.geomType = wkbPoint;
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("BCNLAT")) );
        layerConf.srcLayers.push_back( new NAVISRCLayerOBJNAMSign(srcDataSource->GetLayerByName("BCNSPP")) );
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("BOYCAR")) );
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("BOYLAT")) );
        layerConf.srcLayers.push_back( new NAVISRCLayerOBJNAMSign(srcDataSource->GetLayerByName("BOYSAW")) );
        layerConf.srcLayers.push_back( new NAVISRCLayerLIGHTSSign(srcDataSource->GetLayerByName("LIGHTS")) );
        fieldForCopy.fieldName = "COLOUR";
        fieldForCopy.fieldType = OFTReal;
        layerConf.fieldsForCopy.push_back(fieldForCopy);
        configuration.push_back(layerConf);

        layerConf.srcLayers.clear();
        layerConf.fieldsForCopy.clear();

        layerConf.layerName = "anchor_parking_plg";
        layerConf.geomType = wkbPolygon;
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("ACHARE")) );
        configuration.push_back(layerConf);

        layerConf.srcLayers.clear();

        layerConf.layerName = "anchor_parking_pt";
        layerConf.geomType = wkbPoint;
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("ACHARE")) );
        configuration.push_back(layerConf);

        layerConf.srcLayers.clear();

        layerConf.layerName = "building_ln";
        layerConf.geomType = wkbLineString;
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("DYKCON")) );
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("SLCONS")) );
        configuration.push_back(layerConf);

        layerConf.srcLayers.clear();

        layerConf.layerName = "building_plg";
        layerConf.geomType = wkbPolygon;
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("BUAARE")) );
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("DOCARE")) );
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("SLCONS")) );
        configuration.push_back(layerConf);

        layerConf.srcLayers.clear();

        layerConf.layerName = "called_sea_parts";
        layerConf.geomType = wkbPolygon;
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("SEAARE")) );
        configuration.push_back(layerConf);

        layerConf.srcLayers.clear();

        layerConf.layerName = "coastline";
        layerConf.geomType = wkbLineString;
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("COALNE")) );
        configuration.push_back(layerConf);

        layerConf.srcLayers.clear();

        layerConf.layerName = "depths_area_ln";
        layerConf.geomType = wkbLineString;
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("DEPARE")) );
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("DEPCNT")) );
        configuration.push_back(layerConf);

        layerConf.srcLayers.clear();

        layerConf.layerName = "depths_area_plg";
        layerConf.geomType = wkbPolygon;
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("DEPARE")) );
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("DRGARE")) );
        fieldForCopy.fieldName = "DRVAL2";
        fieldForCopy.fieldType = OFTInteger;
        layerConf.fieldsForCopy.push_back(fieldForCopy);
        configuration.push_back(layerConf);

        layerConf.srcLayers.clear();
        layerConf.fieldsForCopy.clear();

        layerConf.layerName = "dump_plg";
        layerConf.geomType = wkbPolygon;
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("DMPGRD")) );
        configuration.push_back(layerConf);

        layerConf.srcLayers.clear();

        layerConf.layerName = "land_region_ln";
        layerConf.geomType = wkbLineString;
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("SLOTOP")) );
        configuration.push_back(layerConf);

        layerConf.srcLayers.clear();

        layerConf.layerName = "land_region_plg";
        layerConf.geomType = wkbPolygon;
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("LNDARE")) );
        layerConf.srcLayers.push_back( new NAVISRCLayerOBJNAMSign(srcDataSource->GetLayerByName("LNDRGN")) );
        configuration.push_back(layerConf);

        layerConf.srcLayers.clear();

        layerConf.layerName = "land_region_pt";
        layerConf.geomType = wkbPoint;
        layerConf.hasSignature = true;
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("LNDARE")) );
        layerConf.srcLayers.push_back( new NAVISRCLayerOBJNAMSign(srcDataSource->GetLayerByName("LNDRGN")) );
        configuration.push_back(layerConf);

        layerConf.srcLayers.clear();

        layerConf.layerName = "landmark";
        layerConf.geomType = wkbPoint;
        layerConf.hasSignature = false;
        layerConf.srcLayers.push_back( new NAVISRCLayerOBJNAMSign(srcDataSource->GetLayerByName("LNDMRK")) );
        configuration.push_back(layerConf);

        layerConf.srcLayers.clear();

        layerConf.layerName = "magnetic_declination";
        layerConf.geomType = wkbPoint;
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("MAGVAR")) );
        configuration.push_back(layerConf);

        layerConf.srcLayers.clear();

        layerConf.layerName = "mark";
        layerConf.geomType = wkbPoint;
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("DAYMAR")) );
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("SOUNDG")) );
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("TOPMAR")) );
        configuration.push_back(layerConf);

        layerConf.srcLayers.clear();

        layerConf.layerName = "obstacles_ln";
        layerConf.geomType = wkbLineString;
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("CBLSUB")) );
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("FSHFAC")) );
        configuration.push_back(layerConf);

        layerConf.srcLayers.clear();

        layerConf.layerName = "obstacles_plg";
        layerConf.geomType = wkbPolygon;
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("OBSTRN")) );
        configuration.push_back(layerConf);

        layerConf.srcLayers.clear();

        layerConf.layerName = "obstacles_pt";
        layerConf.geomType = wkbPoint;
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("OBSTRN")) );
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("SBDARE")) );
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("UWTROC")) );
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("WRECKS")) );
        configuration.push_back(layerConf);

        layerConf.srcLayers.clear();

        layerConf.layerName = "pile_pt";
        layerConf.geomType = wkbPoint;
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("PILPNT")) );
        configuration.push_back(layerConf);

        layerConf.srcLayers.clear();

        layerConf.layerName = "rivers";
        layerConf.geomType = wkbPolygon;
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("RIVERS")) );
        configuration.push_back(layerConf);

        layerConf.srcLayers.clear();

        layerConf.layerName = "route_ln";
        layerConf.geomType = wkbLineString;
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("NAVLNE")) );
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("RECTRC")) );
        configuration.push_back(layerConf);

        layerConf.srcLayers.clear();

        layerConf.layerName = "route_plg";
        layerConf.geomType = wkbPolygon;
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("CTNARE")) );
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("FAIRWY")) );
        configuration.push_back(layerConf);

        layerConf.srcLayers.clear();

        layerConf.layerName = "vegetation";
        layerConf.geomType = wkbPolygon;
        layerConf.srcLayers.push_back( new NAVISRCLayer(srcDataSource->GetLayerByName("VEGATN")) );
        configuration.push_back(layerConf);

        layerConf.srcLayers.clear();

        return configuration;
    }
}

NAVI2PG::NAVILayer::NAVILayer(
            const CPLString& layerName,
            OGRwkbGeometryType geomType,
            std::vector<NAVISRCLayer*> srcLayers,
            std::vector<FieldForCopy> fieldsToCopy)
    : LayerName_(layerName),
      LayerGeometryType_(geomType),
      SrcLayers_(srcLayers),
      FieldsToCopy_(fieldsToCopy)
{

}

void NAVI2PG::NAVILayer::CopyTo(OGRDataSource *poDstDatasource)
{
    if(SrcLayers_.size() == 0)
    {
        CPLString errMsg;
        errMsg.Printf("Warrning. %s layer not create. Source not found", LayerName_.c_str());
        LOG(errMsg);
        return;
    }

    if( !CheckSpatialReferences() )
    {
        //TODO set exception
        CPLString errMsg;
        errMsg.Printf("Error. %s layer creation error. Spatial references are not equal", LayerName_.c_str());
        LOG(errMsg);

        return;
    }

    OGRLayer *poLayer =
        poDstDatasource->CreateLayer( LayerName_.c_str(), SrcLayers_[0]->getOGRLayer()->GetSpatialRef(), LayerGeometryType_, NULL );

    InitFields(poLayer);
    AddFieldsForCopy(poLayer);

    for(size_t iLayer = 0; iLayer < SrcLayers_.size(); ++iLayer)
    {
        OGRLayer *poSrcLayer = SrcLayers_[iLayer]->getOGRLayer();

        poSrcLayer->ResetReading();

        OGRFeature *poFeatureFrom;
        OGRFeature *poFeatureTo;

        while( (poFeatureFrom = poSrcLayer->GetNextFeature()) != NULL )
        {
            poFeatureTo = OGRFeature::CreateFeature(poLayer->GetLayerDefn());

            OGRGeometry *poGeometry = poFeatureFrom->GetGeometryRef();

            if( poGeometry == NULL
                || wkbFlatten(poGeometry->getGeometryType()) != poLayer->GetLayerDefn()->GetGeomType() )
            {
                //TODO Debug Info
                continue;
            }

            poFeatureTo->SetGeometry(poGeometry);

            CopyFields(poFeatureFrom, poFeatureTo);
            SetFields(SrcLayers_[iLayer], poFeatureFrom, poFeatureTo);

            poLayer->CreateFeature(poFeatureTo);

            OGRFeature::DestroyFeature( poFeatureFrom );
            OGRFeature::DestroyFeature( poFeatureTo );
        }
    }
}

bool NAVI2PG::NAVILayer::CheckSpatialReferences()
{
    for(size_t iLayer = 1; iLayer < SrcLayers_.size(); ++iLayer)
    {
        OGRSpatialReference *sr1 =  SrcLayers_[iLayer-1]->getOGRLayer()->GetSpatialRef();
        OGRSpatialReference *sr2 =  SrcLayers_[iLayer]->getOGRLayer()->GetSpatialRef();

        if ( !sr1->IsSame(sr2))
            return false;
    }

    return true;
}

void NAVI2PG::NAVILayer::AddFieldsForCopy(OGRLayer *poLayer)
{
    for(size_t iField = 0; iField< FieldsToCopy_.size(); ++iField)
    {
        OGRFieldDefn oFieldType( FieldsToCopy_[iField].fieldName, FieldsToCopy_[iField].fieldType );
        oFieldType.SetWidth(32);

        if( poLayer->CreateField( &oFieldType ) != OGRERR_NONE )
        {
            //TODO Set exception
            LOG( "Creating field failed.\n" );
            return;
        }
    }
}

void NAVI2PG::NAVILayer::CopyFields(OGRFeature* srcFeature, OGRFeature* dstFeature)
{
    for(size_t iField = 0; iField< FieldsToCopy_.size(); ++iField)
    {
        dstFeature->SetField( FieldsToCopy_[iField].fieldName,  srcFeature->GetFieldAsInteger(FieldsToCopy_[iField].fieldName));
    }
}

NAVI2PG::NAVILayerSimple::NAVILayerSimple(
        const CPLString &layerName,
        OGRwkbGeometryType geomType,
        std::vector<NAVISRCLayer*> srcLayers,
        std::vector<FieldForCopy> fieldsToCopy)
    : NAVILayer(layerName, geomType, srcLayers, fieldsToCopy)
{

}

void NAVI2PG::NAVILayerSimple::InitFields(OGRLayer *poLayer)
{
    OGRFieldDefn oFieldType( "type", OFTString );
    oFieldType.SetWidth(32);
    OGRFieldDefn oFieldNameEn( "name_en", OFTString );
    oFieldType.SetWidth(32);
    OGRFieldDefn oFieldNameRu( "name_ru", OFTString );
    oFieldType.SetWidth(32);

    if( poLayer->CreateField( &oFieldType ) != OGRERR_NONE ||
            poLayer->CreateField( &oFieldNameEn ) != OGRERR_NONE ||
            poLayer->CreateField( &oFieldNameRu ) != OGRERR_NONE)
    {
        //TODO Set exception
        LOG( "Creating field failed.\n" );
        return;
    }
}

void NAVI2PG::NAVILayerSimple::SetFields(NAVISRCLayer* srcLayer, OGRFeature* srcFeature, OGRFeature* dstFeature)
{
    SetTypeField(srcLayer, dstFeature);
    SetNameEnField(srcLayer, srcFeature, dstFeature);
    SetNameRuField(srcLayer, srcFeature, dstFeature);
}

void NAVI2PG::NAVILayerSimple::SetTypeField(NAVISRCLayer* srcLayer, OGRFeature* dstFeature)
{
    dstFeature->SetField( "type",  srcLayer->getOGRLayer()->GetName());
}

void NAVI2PG::NAVILayerSimple::SetNameRuField(NAVISRCLayer* srcLayer, OGRFeature* srcFeature, OGRFeature* dstFeature)
{
    dstFeature->SetField( "name_en",  srcLayer->GetNameRuField(srcFeature));
}

void NAVI2PG::NAVILayerSimple::SetNameEnField(NAVISRCLayer* srcLayer, OGRFeature* srcFeature, OGRFeature* dstFeature)
{
    dstFeature->SetField( "name_en",  srcLayer->GetNameEnField(srcFeature));
}

NAVI2PG::NAVISRCLayer::NAVISRCLayer(OGRLayer* srcOGRLayer)
    : poLayer(srcOGRLayer)
{

}
OGRLayer* NAVI2PG::NAVISRCLayer::getOGRLayer()
{
    return poLayer;
}

CPLString NAVI2PG::NAVISRCLayer::GetNameEnField(OGRFeature *srcFeature)
{
    return CPLString("");
}
CPLString NAVI2PG::NAVISRCLayer::GetNameRuField(OGRFeature *srcFeature)
{
    return CPLString("");
}

CPLString NAVI2PG::NAVISRCLayerOBJNAMSign::GetNameEnField(OGRFeature *srcFeature)
{
    return CPLString(srcFeature->GetFieldAsString( "OBJNAM" ));
}
CPLString NAVI2PG::NAVISRCLayerOBJNAMSign::GetNameRuField(OGRFeature *srcFeature)
{
    return CPLString(srcFeature->GetFieldAsString( "OBJNAM" ));
}

CPLString NAVI2PG::NAVISRCLayerLIGHTSSign::GetNameEnField(OGRFeature *srcFeature)
{
    /*
    concat (
        CASE
            WHEN  "LITCHR" =  '2' THEN 'FI'
            WHEN  "LITCHR" =  '3' THEN 'LFI'
            WHEN  "LITCHR" =  '4' THEN 'Q'
            WHEN  "LITCHR" =  '7' THEN 'lso'
            WHEN  "LITCHR" =  '8' THEN 'OcR'
            WHEN  "LITCHR" =  '25' THEN 'Q+LFI'
            ELSE 'NA'
        END,
        "SIGGRP" ,
        CASE
            WHEN  "COLOUR" =  '1' THEN 'W'
            WHEN  "COLOUR" =  '3' THEN 'R'
            ELSE 'G'
        END,
        ' ',
        CASE
            WHEN "SIGPER"  IS NULL THEN ''
            ELSE concat("SIGPER" ,'s')
        END,
        CASE
            WHEN "HEIGHT"  IS NULL THEN ''
            ELSE concat("HEIGHT" ,'m')
        END,
        CASE
            WHEN "VALNMR"  IS NULL THEN ''
            ELSE concat("VALNMR" ,'M')
        END
    )
     */


    int litchrInt = srcFeature->GetFieldAsInteger( "LITCHR" );
    CPLString litchrStr;
    switch(litchrInt)
    {
        case(2):
        {
            litchrStr.Printf("%s", "FI");
            break;
        }
        case(3):
        {
            litchrStr.Printf("%s", "LFI");
            break;
        }
        case(4):
        {
            litchrStr.Printf("%s", "Q");
            break;
        }
        case(7):
        {
            litchrStr.Printf("%s", "lso");
            break;
        }
        case(8):
        {
            litchrStr.Printf("%s", "OcR");
            break;
        }
        case(25):
        {
            litchrStr.Printf("%s", "Q+LFI");
            break;
        }
        default:
        {
            litchrStr="";
            break;
        }
    }

    CPLString siggrpStr(srcFeature->GetFieldAsString( "SIGGRP" ) );

    int colourInt = srcFeature->GetFieldAsInteger( "COLOUR" );
    CPLString colourStr;
    switch(colourInt)
    {
        case(1):
        {
            colourStr.Printf("%s", "W");
            break;
        }
        case(3):
        {
            colourStr.Printf("%s", "R");
            break;
        }
        default:
        {
            colourStr = "";
        }
    }

    CPLString sigperStr(srcFeature->GetFieldAsString( "SIGPER" ) );
    if(sigperStr != "")
        sigperStr.Printf("%ss",sigperStr.c_str());

    CPLString heightStr(srcFeature->GetFieldAsString( "HEIGHT" ) );
    if(heightStr != "")
        heightStr.Printf("%sm",heightStr.c_str());

    CPLString valnmrStr(srcFeature->GetFieldAsString( "VALNMR" ) );
    if(valnmrStr != "")
        valnmrStr.Printf("%sM",valnmrStr.c_str());

    CPLString nameEn;
    nameEn.Printf("%s%s%s %s%s%s",litchrStr.c_str(), siggrpStr.c_str(), colourStr.c_str(), sigperStr.c_str(), heightStr.c_str(), valnmrStr.c_str());

    return nameEn;
}
CPLString NAVI2PG::NAVISRCLayerLIGHTSSign::GetNameRuField(OGRFeature *srcFeature)
{
    return GetNameEnField(srcFeature);
}

void NAVI2PG::Import(const char  *pszS57DataSource, const char  *pszPGConnectionString)
{
    CPLString msg;

    msg.Printf("pszS57DataSource: %s", pszS57DataSource);
    LOG(msg);

    msg.Printf("pszPGConnectionString: %s", pszPGConnectionString);
    LOG(msg);

    CPLSetConfigOption("OGR_S57_OPTIONS", "RETURN_PRIMITIVES=ON,RETURN_LINKAGES=OFF,LNAM_REFS=ON,SPLIT_MULTIPOINT=ON,ADD_SOUNDG_DEPTH=ON,RECODE_BY_DSSI=ON");
    //CPLSetConfigOption("OGR_S57_OPTIONS", "RETURN_PRIMITIVES=ON,RETURN_LINKAGES=ON,LNAM_REFS=ON");

    OGRRegisterAll();

    const char *pszSrcDriverName = "S57";
    const char *pszDstDriverName = "PostgreSQL";

    OGRSFDriver *poSrcDriver = NULL;
    OGRSFDriver *poDstDriver = NULL;


    poSrcDriver = OGRSFDriverRegistrar::GetRegistrar()->GetDriverByName(
                pszSrcDriverName );

    if( poSrcDriver == NULL )
    {
        CPLString msg;
        msg.Printf("%s driver not available.", pszSrcDriverName);
        LOG(msg);
        exit( 1 );
    }

    OGRDataSource *poSrcDatasource = NULL;





    poSrcDatasource = poSrcDriver->Open(pszS57DataSource);

    if( poSrcDatasource == NULL )
    {
        CPLString msg;
        msg.Printf("Open S57 failed.");
        LOG(msg);
        exit( 1 );
    }

    poDstDriver = OGRSFDriverRegistrar::GetRegistrar()->GetDriverByName(
                pszDstDriverName );

    if( poDstDriver == NULL )
    {
        CPLString msg;
        msg.Printf("%s driver not available.", pszDstDriverName);
        LOG(msg);
        exit( 1 );
    }

    OGRDataSource *poDstDatasource = NULL;

    poDstDatasource = poDstDriver->Open(pszPGConnectionString);


    if( poDstDatasource == NULL )
    {
        CPLString msg;
        msg.Printf("Creation of table in PG Database failed.");
        LOG(msg);
        exit( 1 );
    }


    /*
     *  For tests
     */
    /*
    OGRLayer *poLayer = poSrcDatasource->GetLayerByName("LNDRGN");
    OGRFeatureDefn *poFDefn = poLayer->GetLayerDefn();

    OGRFeature *poFeature = poLayer->GetNextFeature();

    for( int iField = 0; iField < poFDefn->GetFieldCount(); iField++ )
    {
        std::cout <<   poFeature->GetFieldAsInteger(iField ) << "(" << poFDefn->GetFieldDefn(iField)->GetNameRef() << "), ";
    }
    std::cout << std::endl;

    poFeature = poLayer->GetNextFeature();

    for( int iField = 0; iField < poFDefn->GetFieldCount(); iField++ )
    {
        std::cout <<   poFeature->GetFieldAsString( iField ) << "(" << poFDefn->GetFieldDefn(iField)->GetNameRef() << "), ";
    }
    std::cout << std::endl;
    */


    Navi2PGConfig config = configurate(poSrcDatasource);

    for(size_t iConfNode = 0; iConfNode < config.size(); ++iConfNode)
    {
        NAVI2PG::NAVILayer* naviLayer;

        naviLayer =
            new NAVI2PG::NAVILayerSimple (
                config[iConfNode].layerName,
                config[iConfNode].geomType,
                config[iConfNode].srcLayers,
                config[iConfNode].fieldsForCopy);

        naviLayer->CopyTo(poDstDatasource);
    }


    OGRDataSource::DestroyDataSource( poSrcDatasource );
    OGRDataSource::DestroyDataSource( poDstDatasource );
}
