#include "usbd_cdc_if.h"

static uint8_t rx_buffer[USB_RX_BUFFER_SIZE];
uint8_t tx_buffer[USB_TX_BUFFER_SIZE];
extern USBD_HandleTypeDef USB_Device;

static int8_t CDC_Init(void);
static int8_t CDC_DeInit(void);
static int8_t CDC_Control(uint8_t cmd, uint8_t *pbuf, uint16_t length);
static int8_t CDC_Receive(uint8_t *Buf, uint32_t *Len);
static int8_t CDC_TransmitDone(uint8_t *Buf, uint32_t *Len, uint8_t epnum);

// clang-format off
USBD_CDC_ItfTypeDef USBD_CDC_Template_fops = {
    CDC_Init,
    CDC_DeInit,
    CDC_Control,
    CDC_Receive,
    CDC_TransmitDone
};
// clang-format on

USBD_CDC_LineCodingTypeDef linecoding = {
    115200, /* baud rate*/
    0x00,   /* stop bits-1*/
    0x00,   /* parity - none*/
    0x08    /* nb. of bits 8*/
};

/**
 * @brief  CDC_Init
 *         Initializes the CDC media low layer
 * @retval Result of the operation: USBD_OK if all operations are OK else USBD_FAIL
 */
static int8_t CDC_Init(void) {
    USBD_CDC_SetRxBuffer(&USB_Device, rx_buffer);
    USBD_CDC_SetTxBuffer(&USB_Device, tx_buffer, USB_TX_BUFFER_SIZE);

    return (0);
}

/**
 * @brief  CDC_DeInit
 *         DeInitializes the CDC media low layer
 * @param  None
 * @retval Result of the operation: USBD_OK if all operations are OK else USBD_FAIL
 */
static int8_t CDC_DeInit(void) {
    /*
       Add your deinitialization code here
    */
    return (0);
}

/**
 * @brief  CDC_Control
 *         Manage the CDC class requests
 * @param  Cmd: Command code
 * @param  Buf: Buffer containing command data (request parameters)
 * @param  Len: Number of data to be sent (in bytes)
 * @retval Result of the operation: USBD_OK if all operations are OK else USBD_FAIL
 */
static int8_t CDC_Control(uint8_t cmd, uint8_t *pbuf, uint16_t length) {
    UNUSED(length);

    switch (cmd) {
        case CDC_SEND_ENCAPSULATED_COMMAND:
            /* Add your code here */
            break;

        case CDC_GET_ENCAPSULATED_RESPONSE:
            /* Add your code here */
            break;

        case CDC_SET_COMM_FEATURE:
            /* Add your code here */
            break;

        case CDC_GET_COMM_FEATURE:
            /* Add your code here */
            break;

        case CDC_CLEAR_COMM_FEATURE:
            /* Add your code here */
            break;

        case CDC_SET_LINE_CODING:
            linecoding.bitrate =
                (uint32_t)(pbuf[0] | (pbuf[1] << 8) | (pbuf[2] << 16) | (pbuf[3] << 24));
            linecoding.format = pbuf[4];
            linecoding.paritytype = pbuf[5];
            linecoding.datatype = pbuf[6];

            /* Add your code here */
            break;

        case CDC_GET_LINE_CODING:
            pbuf[0] = (uint8_t)(linecoding.bitrate);
            pbuf[1] = (uint8_t)(linecoding.bitrate >> 8);
            pbuf[2] = (uint8_t)(linecoding.bitrate >> 16);
            pbuf[3] = (uint8_t)(linecoding.bitrate >> 24);
            pbuf[4] = linecoding.format;
            pbuf[5] = linecoding.paritytype;
            pbuf[6] = linecoding.datatype;

            /* Add your code here */
            break;

        case CDC_SET_CONTROL_LINE_STATE:
            /* Add your code here */
            break;

        case CDC_SEND_BREAK:
            /* Add your code here */
            break;

        default:
            break;
    }

    return (0);
}

/**
 * @brief  CDC_Receive
 *         Data received over USB OUT endpoint are sent over CDC interface
 *         through this function.
 *
 *         @note
 *         This function will issue a NAK packet on any OUT packet received on
 *         USB endpoint until exiting this function. If you exit this function
 *         before transfer is complete on CDC interface (ie. using DMA controller)
 *         it will result in receiving more data while previous ones are still
 *         not sent.
 *
 * @param  buf: Buffer of data to be received
 * @param  len: Number of data received (in bytes)
 * @retval Result of the operation: USBD_OK if all operations are OK else USBD_FAIL
 */
static int8_t CDC_Receive(uint8_t *buf, uint32_t *len) {
    if (*len == 1) {
        HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
    }

    USBD_CDC_SetRxBuffer(&USB_Device, &buf[0]);
    USBD_CDC_ReceivePacket(&USB_Device);

    return (0);
}

/**
 * @brief  CDC_TransmitDone
 *         Data transmitted callback
 *
 *         @note
 *         This function is IN transfer complete callback used to inform user that
 *         the submitted Data is successfully sent over USB.
 *
 * @param  Buf: Buffer of data to be received
 * @param  Len: Number of data received (in bytes)
 * @retval Result of the operation: USBD_OK if all operations are OK else USBD_FAIL
 */
static int8_t CDC_TransmitDone(uint8_t *Buf, uint32_t *Len, uint8_t epnum) {
    USBD_CDC_HandleTypeDef *hcdc = (USBD_CDC_HandleTypeDef *)USB_Device.pClassData;
    hcdc->TxState = 0;

    UNUSED(Buf);
    UNUSED(Len);
    UNUSED(epnum);

    return (0);
}

uint8_t CDC_Transmit(uint8_t *buffer, uint32_t len) {
    USBD_CDC_HandleTypeDef *hcdc = (USBD_CDC_HandleTypeDef *)USB_Device.pClassData;
    if (hcdc->TxState != 0) {
        return USBD_BUSY;
    }
    USBD_CDC_SetTxBuffer(&USB_Device, buffer, len);

    return USBD_CDC_TransmitPacket(&USB_Device);
}
