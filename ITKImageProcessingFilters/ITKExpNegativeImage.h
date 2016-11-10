// File automatically generated

/*
 * Your License or Copyright can go here
 */

#ifndef _ITKExpNegativeImage_h_
#define _ITKExpNegativeImage_h_

#include "ITKImageBase.h"

#include "SIMPLib/SIMPLib.h"
#include "SIMPLib/Common/SIMPLibSetGetMacros.h"

//Auto includes
#include <itkExpNegativeImageFilter.h>


/**
 * @brief The ITKExpNegativeImage class. See [Filter documentation](@ref ITKExpNegativeImage) for details.
 */
class ITKExpNegativeImage : public ITKImageBase
{
  Q_OBJECT

  public:
    SIMPL_SHARED_POINTERS(ITKExpNegativeImage)
    SIMPL_STATIC_NEW_MACRO(ITKExpNegativeImage)
    SIMPL_TYPE_MACRO_SUPER(ITKExpNegativeImage, AbstractFilter)

    virtual ~ITKExpNegativeImage();



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
    ITKExpNegativeImage();

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

    ITKExpNegativeImage(const ITKExpNegativeImage&); // Copy Constructor Not Implemented
    void operator=(const ITKExpNegativeImage&); // Operator '=' Not Implemented
};

#endif /* _ITKExpNegativeImage_H_ */
