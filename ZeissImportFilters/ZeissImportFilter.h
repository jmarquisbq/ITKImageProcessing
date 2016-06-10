/*
 * Your License or Copyright Information can go here
 */

#ifndef _zeissimportfilter_h_
#define _zeissimportfilter_h_


#include <QtCore/QString>
#include <QtCore/QDateTime>
#include <QtXml/QDomDocument>

#include "SIMPLib/SIMPLib.h"
#include "SIMPLib/Common/SIMPLibSetGetMacros.h"
#include "SIMPLib/Common/AbstractFilter.h"
#include "SIMPLib/DataArrays/StringDataArray.hpp"
#include "SIMPLib/FilterParameters/FloatVec3FilterParameter.h"

#include "ZeissImport/ZeissXml/ZeissTagsXmlSection.h"

// our PIMPL private class
class ZeissImportFilterPrivate;

/**
 * @class ZeissImportFilter ZeissImportFilter.h ZeissImport/ZeissImportFilters/ZeissImportFilter.h
 * @brief
 * @author
 * @date
 * @version 1.0
 */
class ZeissImportFilter : public AbstractFilter
{
  Q_OBJECT /* Need this for Qt's signals and slots mechanism to work */
    Q_DECLARE_PRIVATE(ZeissImportFilter)

  public:
    SIMPL_SHARED_POINTERS(ZeissImportFilter)
    SIMPL_STATIC_NEW_MACRO(ZeissImportFilter)
    SIMPL_TYPE_MACRO_SUPER(ZeissImportFilter, AbstractFilter)

    virtual ~ZeissImportFilter();

    SIMPL_FILTER_PARAMETER(QString, InputFile)
    Q_PROPERTY(QString InputFile READ getInputFile WRITE setInputFile)

    SIMPL_FILTER_PARAMETER(QString, DataContainerName)
    Q_PROPERTY(QString DataContainerName READ getDataContainerName WRITE setDataContainerName)

    SIMPL_FILTER_PARAMETER(QString, ImageAttributeMatrixName)
    Q_PROPERTY(QString ImageAttributeMatrixName READ getImageAttributeMatrixName WRITE setImageAttributeMatrixName)

    SIMPL_FILTER_PARAMETER(QString, ImageDataArrayPrefix)
    Q_PROPERTY(QString ImageDataArrayPrefix READ getImageDataArrayPrefix WRITE setImageDataArrayPrefix)

    SIMPL_FILTER_PARAMETER(bool, ConvertToGrayScale)
    Q_PROPERTY(bool ConvertToGrayScale READ getConvertToGrayScale WRITE setConvertToGrayScale)

    SIMPL_FILTER_PARAMETER(FloatVec3_t, ColorWeights)
    Q_PROPERTY(FloatVec3_t ColorWeights READ getColorWeights WRITE setColorWeights)

    SIMPL_FILTER_PARAMETER(bool, FileWasRead)
    Q_PROPERTY(bool FileWasRead READ getFileWasRead)

    /**
     * @brief getCompiledLibraryName Reimplemented from @see AbstractFilter class
     */
    virtual const QString getCompiledLibraryName();

    /**
     * @brief getBrandingString Returns the branding string for the filter, which is a tag
     * used to denote the filter's association with specific plugins
     * @return Branding string
    */
    virtual const QString getBrandingString();

    /**
     * @brief getFilterVersion Returns a version string for this filter. Default
     * value is an empty string.
     * @return
     */
    virtual const QString getFilterVersion();

    /**
     * @brief newFilterInstance Reimplemented from @see AbstractFilter class
     */
    virtual AbstractFilter::Pointer newFilterInstance(bool copyFilterParameters);

    /**
     * @brief getGroupName Reimplemented from @see AbstractFilter class
     */
    virtual const QString getGroupName();

    /**
     * @brief getSubGroupName Reimplemented from @see AbstractFilter class
     */
    virtual const QString getSubGroupName();

    /**
     * @brief getHumanLabel Reimplemented from @see AbstractFilter class
     */
    virtual const QString getHumanLabel();

    /**
     * @brief setupFilterParameters Reimplemented from @see AbstractFilter class
     */
    virtual void setupFilterParameters();

    /**
     * @brief writeFilterParameters Reimplemented from @see AbstractFilter class
     */
    virtual int writeFilterParameters(AbstractFilterParametersWriter* writer, int index);

    /**
     * @brief readFilterParameters Reimplemented from @see AbstractFilter class
     */
    virtual void readFilterParameters(AbstractFilterParametersReader* reader, int index);

    /**
     * @brief execute Reimplemented from @see AbstractFilter class
     */
    virtual void execute();

    /**
    * @brief preflight Reimplemented from @see AbstractFilter class
    */
    virtual void preflight();


    SIMPL_PIMPL_PROPERTY_DECL(QDomElement, Root)
    SIMPL_PIMPL_PROPERTY_DECL(ZeissTagsXmlSection::Pointer, RootTagsSection)
    SIMPL_PIMPL_PROPERTY_DECL(QString, InputFile_Cache)
    SIMPL_PIMPL_PROPERTY_DECL(QDateTime, LastRead)

  signals:
    /**
     * @brief updateFilterParameters This is emitted when the filter requests all the latest Filter Parameters need to be
     * pushed from a user facing control such as the FilterParameter Widget
     * @param filter The filter to push the values into
     */
    void updateFilterParameters(AbstractFilter* filter);

    /**
     * @brief parametersChanged This signal can be emitted when any of the filter parameters are changed internally.
     */
    void parametersChanged();

    /**
     * @brief preflightAboutToExecute Emitted just before the dataCheck() is called. This can change if needed.
     */
    void preflightAboutToExecute();

    /**
     * @brief preflightExecuted Emitted just after the dataCheck() is called. Typically. This can change if needed.
     */
    void preflightExecuted();

  protected:
    ZeissImportFilter();

    /**
     * @brief dataCheck Checks for the appropriate parameter values and availability of arrays
     */
    void dataCheck();

    /**
     * @brief Initializes all the private instance variables.
     */
    void initialize();


    /**
     * @brief readMetaXml
     * @param device
     * @return
     */
    int readMetaXml(QIODevice* device);

    /**
     * @brief parseRootTagsSection
     * @param tags
     * @return
     */
    ZeissTagsXmlSection::Pointer parseTagsSection(QDomElement& tags);

    /**
     * @brief parseImages
     * @param rootTags
     */
    void parseImages(QDomElement& root, ZeissTagsXmlSection::Pointer rootTagsSection);

    /**
     * @brief getImageDimensions
     * @param photoTagsSection
     * @return
     */
    QVector<size_t> getImageDimensions(ZeissTagsXmlSection::Pointer photoTagsSection);

    /**
     * @brief generateMetaDataAttributeMatrix
     * @param photoTagsSection
     * @param imageCount
     * @return
     */
    void addMetaData(AttributeMatrix::Pointer metaAm, ZeissTagsXmlSection::Pointer photoTagsSection, int index);

    /**
     * @brief generateMetaDataAttributeMatrix -root data
     * @param rootTagsSection
     * @param imageCount
     * @return
     */

    void addRootMetaData(AttributeMatrix::Pointer metaAm, ZeissTagsXmlSection::Pointer rootTagsSection, int index);

    /**
     * @brief generateDataArrays
     * @param imageName
     * @param pTag
     * @param dcName
     */
    void importImage(const QString &imageName, const QString &pTag,
                     const QString &dcName, int imageIndex, StringDataArray::Pointer attributeArrayNames);

    /**
     * @brief convertToGrayScale
     * @param imageName
     * @param pTag
     * @param dcName
     */
    void convertToGrayScale(const QString &imageName, const QString &pTag, const QString &dcName);


  private:
    QScopedPointer<ZeissImportFilterPrivate> const d_ptr;

    /* Your private class instance variables go here. You can use several preprocessor macros to help
     * make sure you have all the variables defined correctly. Those are "DEFINE_DATAARRAY_VARIABLE()"
     * and  DEFINE_DATAARRAY_VARIABLE() which are defined in DREAM3DGetSetMacros.h
     */

    ZeissImportFilter(const ZeissImportFilter&); // Copy Constructor Not Implemented
    void operator=(const ZeissImportFilter&); // Operator '=' Not Implemented
};

#endif /* _ZeissImportFilter_H_ */
