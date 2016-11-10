// File automatically generated

/*
 * Your License or Copyright can go here
 */

#ifndef _ITKMedianProjectionImage_h_
#define _ITKMedianProjectionImage_h_

#include "ITKImageBase.h"

#include "SIMPLib/SIMPLib.h"
#include "SIMPLib/Common/SIMPLibSetGetMacros.h"

//Auto includes
#include <itkMedianProjectionImageFilter.h>
#include <SIMPLib/FilterParameters/DoubleFilterParameter.h>


/**
 * @brief The ITKMedianProjectionImage class. See [Filter documentation](@ref ITKMedianProjectionImage) for details.
 */
class ITKMedianProjectionImage : public ITKImageBase
{
  Q_OBJECT

  public:
    SIMPL_SHARED_POINTERS(ITKMedianProjectionImage)
    SIMPL_STATIC_NEW_MACRO(ITKMedianProjectionImage)
    SIMPL_TYPE_MACRO_SUPER(ITKMedianProjectionImage, AbstractFilter)

    virtual ~ITKMedianProjectionImage();

    SIMPL_FILTER_PARAMETER(double, ProjectionDimension)
    Q_PROPERTY(double ProjectionDimension READ getProjectionDimension WRITE setProjectionDimension)



    /**
     * @brief newFilterInstance Reimplemented from @see AbstractFilter class
     */
    virtual AbstractFilter::Pointer newFilterInstance(bool copyFilterParameters);

    /**
     * @brief getHumanLabel Reimplemented from @see AbstractFilter class
     */
    virtual const QString getHumanLabel();

    /**
     * @brief setupFilterParameters Reimplemented from @see AbstractFilter class
     */
    virtual void setupFilterParameters();

    /**
     * @brief readFilterParameters Reimplemented from @see AbstractFilter class
     */
    virtual void readFilterParameters(AbstractFilterParametersReader* reader, int index);

  protected:
    ITKMedianProjectionImage();

    /**
     * @brief dataCheckInternal overloads dataCheckInternal in ITKImageBase and calls templated dataCheck
     */
    void virtual dataCheckInternal() override;

    /**
     * @brief dataCheck Checks for the appropriate parameter values and availability of arrays
     */
    template<typename PixelType, unsigned int Dimension>
    void dataCheck();

    /**
    * @brief filterInternal overloads filterInternal in ITKImageBase and calls templated filter
    */
    void virtual filterInternal() override;

    /**
    * @brief Applies the filter
    */
    template<typename PixelType, unsigned int Dimension>
    void filter();

  private:

    ITKMedianProjectionImage(const ITKMedianProjectionImage&); // Copy Constructor Not Implemented
    void operator=(const ITKMedianProjectionImage&); // Operator '=' Not Implemented
};

#endif /* _ITKMedianProjectionImage_H_ */
