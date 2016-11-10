// File automatically generated

/*
 * Your License or Copyright can go here
 */

#ifndef _ITKSobelEdgeDetectionImage_h_
#define _ITKSobelEdgeDetectionImage_h_

#include "ITKImageBase.h"

#include "SIMPLib/SIMPLib.h"
#include "SIMPLib/Common/SIMPLibSetGetMacros.h"

//Auto includes
#include <itkSobelEdgeDetectionImageFilter.h>


/**
 * @brief The ITKSobelEdgeDetectionImage class. See [Filter documentation](@ref ITKSobelEdgeDetectionImage) for details.
 */
class ITKSobelEdgeDetectionImage : public ITKImageBase
{
  Q_OBJECT

  public:
    SIMPL_SHARED_POINTERS(ITKSobelEdgeDetectionImage)
    SIMPL_STATIC_NEW_MACRO(ITKSobelEdgeDetectionImage)
    SIMPL_TYPE_MACRO_SUPER(ITKSobelEdgeDetectionImage, AbstractFilter)

    virtual ~ITKSobelEdgeDetectionImage();



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
    ITKSobelEdgeDetectionImage();

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

    ITKSobelEdgeDetectionImage(const ITKSobelEdgeDetectionImage&); // Copy Constructor Not Implemented
    void operator=(const ITKSobelEdgeDetectionImage&); // Operator '=' Not Implemented
};

#endif /* _ITKSobelEdgeDetectionImage_H_ */
