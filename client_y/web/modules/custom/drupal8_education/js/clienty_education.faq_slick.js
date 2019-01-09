/**
 * @file
 * drupal8Education 'drupal8education' plugin collapsible.
 */

(function ($, Drupal, window, document) {

    var settings_EducationTipsSlickConfig = {
        sliderEl: "#slick-education-homepage-tips-and-tricks",
        sliderSettings: {
            infinite: true,
            speed: 300,
            slidesToShow: 1,
            slidesToScroll: 1,
            arrows: true,
            variableWidth: true,
            nextArrow: '<span class="slick-next slick-arrow b-icon-arrow-right"></span>',
            prevArrow: '<span class="slick-prev slick-arrow b-icon-arrow-left"></span>',
            lazyLoad: 'blazy',
            touchMove: false,
            responsive: [
                {
                    breakpoint: 1024,
                    settings: {
                        slidesToShow: 1,
                        slidesToScroll: 1,
                    }
                },
                {
                    breakpoint: 600,
                    settings: {
                        slidesToShow: 1,
                        slidesToScroll: 1,
                    }
                },
                {
                    breakpoint: 480,
                    settings: {
                        infinite: false,
                        slidesToShow: 1,
                        slidesToScroll: 1,
                    }
                }
            ]
        }
    };
    var ETSCs = settings_EducationTipsSlickConfig;

    Drupal.behaviors.EducationTipsSlickConfig = {
        attach: function attach(context, settings) {
            var $tipsSlider = $(ETSCs.sliderEl);
            $tipsSlider.slick(ETSCs.sliderSettings);
        }
    };
}(jQuery, Drupal, this, this.document));
