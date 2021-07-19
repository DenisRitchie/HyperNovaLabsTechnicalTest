////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef __APP_MEDIAPLAYER_H__
#define __APP_MEDIAPLAYER_H__


#include <NsCore/Noesis.h>
#include <NsCore/Interface.h>
#include <NsCore/BaseComponent.h>
#include <NsCore/Delegate.h>
#include <NsApp/MediaElementApi.h>


namespace Noesis
{
class ImageSource;
}

namespace NoesisApp
{

NS_WARNING_PUSH
NS_MSVC_WARNING_DISABLE(4251 4275)

////////////////////////////////////////////////////////////////////////////////////////////////////
/// Controls the playback of audio/video media.
////////////////////////////////////////////////////////////////////////////////////////////////////
class NS_APP_MEDIAELEMENT_API MediaPlayer: public Noesis::BaseComponent
{
public:
    NS_DISABLE_COPY(MediaPlayer)
    MediaPlayer();

    /// Gets the texture for the latest generated frame.
    virtual uint32_t GetWidth() const;

    /// Gets the pixel height of the video.
    virtual uint32_t GetHeight() const;

    /// Gets a value indicating whether the media can be paused.
    virtual bool CanPause() const;

    /// Gets a value that indicating whether the media has audio output.
    virtual bool HasAudio() const;

    /// Gets a value that indicates whether the media has video output.
    virtual bool HasVideo() const;

    /// Gets the percentage of buffering completed for streaming content, represented in a value
    /// between 0 and 1.
    virtual float GetBufferingProgress() const;

    /// Gets the percentage of download progress for content located at a remote server,
    /// represented by a value between 0 and 1. The default is 1.
    virtual float GetDownloadProgress() const;

    /// Gets the duration in seconds of the media.
    virtual double GetDuration() const;

    /// Gets or sets the current position in seconds of the media.
    //@{
    virtual double GetPosition() const;
    virtual void SetPosition(double position);
    //@}

    /// Gets or sets the ratio of speed that media is played at, represented by a value between 0
    /// and the largest float. The default is 1.
    //@{
    virtual float GetSpeedRatio() const;
    virtual void SetSpeedRatio(float speedRatio);
    //@}

    /// Gets or sets the media's volume, represented on a linear scale between 0 and 1. The default
    /// is 0.5.
    //@{
    virtual float GetVolume() const;
    virtual void SetVolume(float volume);
    //@}

    /// Gets or sets the balance between the left and right speaker volumes, represented in a range
    /// between -1 and 1. The default is 0.
    //@{
    virtual float GetBalance() const;
    virtual void SetBalance(float balance);
    //@}

    /// Gets or sets a value that indicates whether the media is muted. The default is false.
    //@{
    virtual bool GetIsMuted() const;
    virtual void SetIsMuted(bool muted);
    //@}

    /// Gets or sets a value that indicates whether the media player will update frames for seek
    /// operations while paused. The default is false.
    //@{
    virtual bool GetScrubbingEnabled() const;
    virtual void SetScrubbingEnabled(bool scrubbing);
    //@}

    /// Starts or resumes media playback
    virtual void Play();

    /// Pauses media playback
    virtual void Pause();

    /// Stops media playback and moves position to the begining
    virtual void Stop();

    /// Gets the texture source for rendering the video
    virtual Noesis::ImageSource* GetTextureSource() const = 0;

    // Events
    //@{

    /// Occurs when buffering has started.
    typedef void BufferingStartedT();
    Noesis::Delegate<BufferingStartedT>& BufferingStarted();

    /// Occurs when buffering has finished.
    typedef void BufferingEndedT();
    Noesis::Delegate<BufferingEndedT>& BufferingEnded();

    /// Occurs when an error is encountered.
    typedef void MediaFailedT(const char* error);
    Noesis::Delegate<MediaFailedT>& MediaFailed();

    /// Occurs when the media is opened.
    typedef void MediaOpenedT();
    Noesis::Delegate<MediaOpenedT>& MediaOpened();

    /// Occurs when the media has finished playback.
    typedef void MediaEndedT();
    Noesis::Delegate<MediaEndedT>& MediaEnded();

    //@}

protected:
    Noesis::Delegate<BufferingStartedT> mBufferingStarted;
    Noesis::Delegate<BufferingEndedT> mBufferingEnded;
    Noesis::Delegate<MediaFailedT> mMediaFailed;
    Noesis::Delegate<MediaOpenedT> mMediaOpened;
    Noesis::Delegate<MediaEndedT> mMediaEnded;
};

NS_WARNING_POP

}


#endif
